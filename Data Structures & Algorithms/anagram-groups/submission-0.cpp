class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mpp;
        for(auto it: strs){
            string temp = it;
            sort(it.begin(), it.end());
            if(mpp.count(it)){
                mpp[it].push_back(temp);
            }
            else{
                mpp[it] = {temp};
            }
        }

        for (auto it: mpp){
            result.push_back(it.second);
        }
    return result;
    }
};
