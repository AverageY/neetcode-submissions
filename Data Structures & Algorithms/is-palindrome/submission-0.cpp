class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            if (!isalnum(static_cast<unsigned char> (s[i]))) {
            i++;
            continue;
            }
            if (!isalnum(static_cast<unsigned char>(s[j]))) {
            j--;
            continue;
            }
            if(static_cast<unsigned char>(tolower(s[i]))==static_cast<unsigned char>(tolower(s[j]))){
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
