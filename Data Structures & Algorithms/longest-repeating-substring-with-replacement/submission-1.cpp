class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        int maxLen = 0;
        int maxFreqInWindow = 0;

        unordered_map<char, int> freq;

        for (int r = 0; r < s.size(); r++) {

            // add current char
            freq[s[r]]++;

            // track highest frequency seen in current/previous valid windows
            maxFreqInWindow = max(maxFreqInWindow, freq[s[r]]);

            // if replacements needed > k, shrink window
            while ((r - l + 1) - maxFreqInWindow > k) {
                freq[s[l]]--;
                l++;
            }

            // update answer
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
        
    }
};
