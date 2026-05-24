class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            // found target
            if(nums[mid] == target) {
                return mid;
            }

            // at least one side is always sorted

            // LEFT HALF IS SORTED
            // example:
            // [4,5,6,7,0,1,2]
            //  L     M
            if(nums[left] <= nums[mid]) {

                // check if target lies inside sorted left half
                // target must be:
                // >= left value
                // < mid value
                if(target >= nums[left] && target < nums[mid]) {

                    // discard right half
                    right = mid - 1;
                }
                else {

                    // target not in sorted left half
                    // must exist on right side
                    left = mid + 1;
                }
            }

            // RIGHT HALF IS SORTED
            // example:
            // [4,5,6,7,0,1,2]
            //          M   R
            else {

                // check if target lies inside sorted right half
                // target must be:
                // > mid value
                // <= right value
                if(target > nums[mid] && target <= nums[right]) {

                    // discard left half
                    left = mid + 1;
                }
                else {

                    // target not in sorted right half
                    // search left side
                    right = mid - 1;
                }
            }
        }

        // target does not exist
        return -1;
    }
};