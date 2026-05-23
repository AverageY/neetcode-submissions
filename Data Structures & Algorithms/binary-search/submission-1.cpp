class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        // questions to find target : use <=
        // questions related to search space : use <
        // not general but search spaces based question
        // let u control space using left and right
        // where either left or right could still be the answer
        // so we never collapse the array to a single point by using = 
        while(left<=right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target){
                return mid;
            }
            //left and right to the either side of mid
            // since we already checked mid
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    return -1;
    }
};
