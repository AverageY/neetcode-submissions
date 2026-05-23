class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i = 0; i< nums.size(); i++){
            if(!mpp.count(nums[i])){
                mpp[nums[i]]++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};