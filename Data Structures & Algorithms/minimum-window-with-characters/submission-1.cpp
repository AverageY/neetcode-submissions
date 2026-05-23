class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> sa;
        unordered_map<char,int> sb;

        //store frequency
        for(int i = 0; i< t.size(); i++) {
            sb[t[i]]++;
        }

        int l = 0;
        int minsize = INT_MAX;
        int left = 0;

            // expand right
            for (int r = 0; r < s.size(); r++) {
            sa[s[r]]++;                         
            
            // if this l and r combo contains sb
            // and size is smaller than minsize yet
            // then update size and store l (to get s.substr(l,minsize))
            while (contains(sa, sb)) {         
            if (r - l + 1 < minsize) {
                minsize = r - l + 1;
                left = l;
            }

            // move l now in order to find even shorter answer
            sa[s[l]]--;                     
            if (sa[s[l]] == 0) sa.erase(s[l]);
            l++;
        }
    }
        if(minsize==INT_MAX) return "";

        return s.substr(left,minsize);
        
    }
private:
    // check if a map contains another map
    bool contains(unordered_map<char, int>& sa, unordered_map<char, int>& sb){
        if(sa.size()<sb.size()) return false;
        for(auto it : sb){
            // if parent map (sa) has an element that is also in sb
            // but freq in sa is less then sa cant contain sb
            if(sa[it.first] < it.second){
                return false;
            }
            
        }
        return true;
    }
};
