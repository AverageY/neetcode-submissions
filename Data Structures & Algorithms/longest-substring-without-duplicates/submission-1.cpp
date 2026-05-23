class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int l = 0;
        int size = 0;
        
        //move r
        for (int r = 0; r< s.size(); r++){

            // if r is already there, and its ahead of L
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l){
                // then move l one ahead of the previous duplicate
                // position of r
                // so now the new r will be unique 
                l = mpp[s[r]]+1;
            }

            // insert r into map
            // due to above check, r will always be either new in map
            // or even if there was already an r, the above check removes it from substring
            // so we can update the index of s[r] in map
            mpp[s[r]] = r;

            size = max(size, r-l+1);
        }
        return size;
    }
};
