#include <iostream>
#include <cctype>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;

        while(i<j){
            // if the char is not alphanumeric then we can ignore it and move the pointer accordingly,
            // we can use isalnum function to check if a char is alphanumeric or not
            if (!isalnum(static_cast<unsigned char> (s[i]))) {
            i++;
            continue;
            }
            if (!isalnum(static_cast<unsigned char>(s[j]))) {
            j--;
            continue;
            }
            
            if(tolower(static_cast<unsigned char>(s[i]))==tolower(static_cast<unsigned char>(s[j]))){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
