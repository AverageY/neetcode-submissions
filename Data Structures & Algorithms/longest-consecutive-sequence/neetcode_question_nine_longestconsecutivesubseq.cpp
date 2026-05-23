#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        int maxlen = 0;

        //store in map for lookup, we dont really need the index, the purpose of this map is to query if +1 or -1 of a number exists in the array in o(1) time,
        // so we can store any value in the map, we just need to check for the presence of the key
        for(int i = 0; i<nums.size(); i++){
            if(mpp.find(nums[i]) == mpp.end()){
            mpp[nums[i]] = i;
            }
        }

        // this piece of code was wrong because it only checks for consecutive numbers in one direction (decreasing)
        // and does not check for consecutive numbers in the increasing direction, so we need to check for both directions to get the correct length of the longest consecutive sequence
        // also if nums[i] is huge then we will be doing a lot of unnecessary checks for numbers that are not in the array

        // for(int i = 0; i< nums.size(); i++){
        //     int len = 1;
        //     for(int j = 1; j<= nums[i]; j++){
        //         if(mpp[nums[i]-j]){
        //             len+=1;
        //         }
        //         else{
        //             maxlen = max(len, maxlen);
        //         }
        //     }
        // }
            

        // idea is to only start counting when nums[i]-1 doesnt exist which will mean its a start of sequence 
        // and only count till nums[i]+1 doesnt exist which will mean its the end of sequence, this way we will only be counting for numbers that are in the array
        // counting is in forward direction only because we start couting at start of sequence which is the smallest number in the sequence, 
        //so we only need to count in forward direction to get the length of the sequence
        for(int i=0; i<nums.size(); i++){
            int len = 1;
            int curr = nums[i];
            if(mpp.find(nums[i]-1) == mpp.end()){
                while(mpp.find(curr+1) != mpp.end()){
                    len++;
                    curr++;

                }
            }
            maxlen = max(len, maxlen);
        }

        return maxlen;
    }
};
