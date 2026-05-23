class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mpp;
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
