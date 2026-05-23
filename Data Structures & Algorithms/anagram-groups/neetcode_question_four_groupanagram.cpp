// takeaway from efficient solution
//Design a key such that all equivalent inputs map to the same representation, and non-equivalent ones don’t.
// think, can I still group things together even if i lose the original input
// this helps in building a unique key

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mpp;

        //sorting 2 strings which are anagrams will give us the same string
        // so we can use the sorted string as key in map and store all the anagrams in vector as value
        // example "eat" and "tea" will both give "aet" when sorted so we can store both of them in vector with key "aet"
        // so if "aet" is already in map then we can just push the current string in vector of that key otherwise we can create a new key and push the current string in vector of that key
        for(auto it: strs){
            string temp = it;
            sort(it.begin(), it.end());
            mpp[it].push_back(temp);
        }

        for (auto it: mpp){
            result.push_back(it.second);
        }
    return result;
    }

public:
    vector<vector<string>> groupAnagramsEfficient(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mpp;

        // instead of sorting we can count the frequency of each character in the string
        // and use that as key in map
        // example "eat" will give us a vector of size 26 with 1 at index 0 (for 'a'), 1 at index 4 (for 'e') and 1 at index 19 (for 't') and rest all will be 0
        // so we can convert this vector to string and use it as key in map and store all the anagrams in vector as value
        // since "eat" and "tea" will give us the same vector of frequency of characters they will have the same key in map and we can store both of them in vector of that key
        // we cannot use vector as key in map so we can convert it to string by concatenating the frequency of each character with a separator (like '#') to avoid ambiguity
        // so instead of sorting we used the fact that anagrams will have the same frequency of characters and we used that as key in map to store all the anagrams in vector as value
        for(auto it: strs){
            vector<int> temp(26,0);
            for(auto x: it){
                temp[x-'a']++;
            }
            string tempstr;
            for(int i = 0; i<=25; i++){
                tempstr += to_string(temp[i]) + '#';
            }
            mpp[tempstr].push_back(it);
        }

        for(auto it: mpp){
            result.push_back(it.second);
        }

    return result;
    }
};
