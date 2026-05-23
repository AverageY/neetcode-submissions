class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp;

        for(int i = 0; i<nums.size(); i++){
            if(!mpp.count(target-nums[i])){
                mpp[nums[i]] = i;
            }
            else{
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
