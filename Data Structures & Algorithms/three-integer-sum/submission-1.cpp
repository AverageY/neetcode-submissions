class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i<nums.size()-1; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1, k = nums.size()-1;
            while(j<k){

                if(nums[i]+nums[j]+nums[k] == 0){
                    result.push_back({nums[i],nums[j], nums[k]});
                    // 2. Skip duplicate j values
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // 3. Skip duplicate k values
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k] > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return result;
    }
};
