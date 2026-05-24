class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int mid = left + (right-left)/2;

            // we are under the wrong range because the dip is to the right
            // so move range to the right
            if(nums[mid]>nums[right]){
                left = mid+1;
            }
            //this is the correct space
            // this is sorted ascending
            else{
                // once we hit the correct space, above if will never be triggered
                // so search space will keep on collapsing right
                // till left = min's index and right = min's index + 1
                // in this case mid = left
                // now since again right = mid => right = left
                // loop condition is left<right, loop breaks with min at left
                right = mid;
            }
        }
        return nums[left];
    }
};
