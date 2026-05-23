class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> sa;
        unordered_map<char,int> sb;

        //store frequency
        for(int i = 0; i< t.size(); i++) {
            sb[t[i]]++;
        }

     // number of UNIQUE chars we need to satisfy
        // example:
        // t = "AABC"
        // required = 3 (A, B, C)
        int required = sb.size();

        // how many unique chars currently satisfy required frequency
        //
        // example:
        // if window has:
        // A -> 1
        // B -> 1
        //
        // formed = 1 (need 1 more A and 1 more C)
        int formed = 0;

        int l = 0;

        // smallest valid window size found so far
        int minsize = INT_MAX;

        // starting index of best answer
        int left = 0;

        // expand window using right pointer
        for (int r = 0; r < s.size(); r++) {

            // include current right character into window
            sa[s[r]]++;

            // if:
            // 1. this character is needed in t
            // 2. current frequency JUST became equal to required frequency
            //
            // then this character requirement is now satisfied
            // so increase formed since one more unique char satisfied
            if (sb.count(s[r]) && sa[s[r]] == sb[s[r]]) {
                formed++;
            }

            // if all required unique chars are satisfied
            // then current window is valid
            while (formed == required) {

                // update smallest answer
                if (r - l + 1 < minsize) {
                    minsize = r - l + 1;
                    left = l;
                }

                // now try shrinking from left
                // to see if we can get smaller valid window

                sa[s[l]]--;

                // if after removing left char,
                // its frequency becomes LESS than required frequency,
                // then window is no longer valid
                // one more char needed
                // so decrease formed by 1
                if (sb.count(s[l]) && sa[s[l]] < sb[s[l]]) {
                    formed--;
                }

                // shrink window
                l++;
            }
        }
        if(minsize==INT_MAX) return "";

        return s.substr(left,minsize);
        
    }

};
