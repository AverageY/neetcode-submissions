#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp;

        for(int i = 0; i<nums.size(); i++){

            //check if the complement of the current number (target - nums[i]) is in map
            if(!mpp.count(target-nums[i])){

                // if not then store its index as value
                // helps us in checking the index of complement when we find it later
                mpp[nums[i]] = i;
            }
            else{

                //if we find the complement then we have our answer
                // push the index of complement and current index in answer vector
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
