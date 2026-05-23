#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // instead of using 3 nested loops we can apply the fundamental 2 pointer approach to get the triplet
        // using current element as the first element of the triplet and
        // then using two pointers to find the other two elements that sum up to 0 with the current element
        // the fundamental principal which needs to be there for the 2 pointer to work is we must be able to do k-- if sum is too large
        // and j++ if sum is too small, this is only possible if the array is sorted, so we sort the array first and then apply the 2 pointer approach

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i<nums.size()-1; i++){

            // current num same as previous we will get same triplet as before so skip it to avoid duplicates in result
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1, k = nums.size()-1;

            while(j<k){

                if(nums[i]+nums[j]+nums[k] == 0){
                    result.push_back({nums[i],nums[j], nums[k]});

                    // sorting grouped the duplicates together, we want the next unique element in the triplet, not just next element
                    // so we skip all the duplicates for j and k to get the next unique element for the triplet
                    // 2. Skip duplicate j values
                    // with this j and k are at last occurence of the duplicated values, and next value is unique
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // 3. Skip duplicate k values
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    
                    // move to the next unique element for the triplet
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
