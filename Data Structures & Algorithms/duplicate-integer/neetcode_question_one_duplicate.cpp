#include <iostream>
#include <unordered_map>

using namespace std;


/*
* Given an integer array nums,
* return true if any value appears more than once in the array, otherwise return false.
*/
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i = 0; i< nums.size(); i++){

            // count() function is used to check if the key is present in the map or not
            if(!mpp.count(nums[i])){

                // if not then put in map so on next occurence this triggers the else check
                mpp[nums[i]]++;
            }
            else{
                // early return if we find a duplicate
                return true;
            }
        }
        return false;
    }
};