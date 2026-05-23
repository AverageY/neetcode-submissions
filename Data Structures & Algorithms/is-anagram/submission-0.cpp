class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }

        unordered_map<char, int> mpps;
        unordered_map<char, int> mppt;

        for(auto x: s){
            mpps[x]++;
        }
        for(auto x: t){
            mppt[x]++;
        }
        for(auto it: mpps){
            if(it.second != mppt[it.first]){
                return false;
            }
        }
        return true;
    }
};
