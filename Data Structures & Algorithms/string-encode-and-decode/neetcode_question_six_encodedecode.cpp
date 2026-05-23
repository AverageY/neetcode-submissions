#include <iostream>

using namespace std;

class Solution {
public:

//example 
//["Hello","World"] -> "5#Hello5#World"
// cant do Hello#world because we cannot guarantee that the original string does not contain the separator character '#', 
//so we need to use a length prefix to ensure that we can correctly parse the original strings during decoding
// this works because even if the original string is 1#2 then our encoding will be 3#1#2 which can be correctly decoded back to 1#2 
//by reading the length prefix first and then extracting the correct number of characters for each string.

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string result = to_string(strs[0].size()) + "#" + strs[0];
        for(int i = 1; i< strs.size(); i++){
            result+= to_string(strs[i].size()) + "#" + strs[i];
        }
    // gives 5#Hello5#World
    return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        // index to keep track of current position for slicing etc
        int i = 0;
        while (i<s.size()){
            // find index where # is starting at i
            int f = s.find('#', i);
            //10#HelloMello5#World
            //i f
            // length number starts at i and ends at found - 1
            // so the length of the length prefix is = found - 1 - i + 1 = found -i
            int length_prefix = stoi(s.substr(i, f-i));
            // move prefix to first char of string
            i = f+1;

            // we know the start and till what length to look
            string temp = s.substr(i, length_prefix);
            result.push_back(temp);

            //again move i to a length prefix of next string for loop to continue
            // currently i at start of string, and the string is length_prefix long
            // to reach the next length_prefix number, move i by length of current string

            i+=length_prefix;
        }
        return result;

    }
};

