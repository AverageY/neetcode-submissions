class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        // ensure nums1 is always smaller
        // because we binary search on nums1
        if(m > n){
            swap(nums1, nums2);
            swap(m, n);
        }

        // length of left half combined from both should be
        // (m+n+1)/2
        // +1 handles odd length properly
        // for odd total length, left half will contain 1 extra element
        int leftpartition = (m + n + 1) / 2;

        int left = 0;

        // iterate over all possible partitions of nums1
        int right = m;

        // lets say partition in nums1 is x
        // and partition in nums2 is y
        //
        // y = leftpartition - x
        //
        // if x is a correct partition then:
        //
        // left of nums1 <= right of nums2
        // left of nums2 <= right of nums1
        //
        // left and right internally are already sorted
        //
        // so valid partition is:
        //
        // nums1[x-1] <= nums2[y]
        // nums2[y-1] <= nums1[x]

        while(left <= right){

            int x = left + (right - left) / 2;

            int y = leftpartition - x;

            // partition boundary values
            //
            // if partition takes nothing from left side
            // then left value becomes -infinity
            //
            // if partition takes entire array into left side
            // then right value becomes +infinity

            int nums1Left =
                (x == 0) ? INT_MIN : nums1[x - 1];

            int nums1Right =
                (x == m) ? INT_MAX : nums1[x];

            int nums2Left =
                (y == 0) ? INT_MIN : nums2[y - 1];

            int nums2Right =
                (y == n) ? INT_MAX : nums2[y];

            // correct partition found

            if(nums1Left <= nums2Right &&
               nums2Left <= nums1Right){

                // odd total length
                // median is largest element of left partition

                if((m + n) % 2 != 0){

                    return max(nums1Left, nums2Left);
                }

                // even total length
                // median is average of:
                // max(left side)
                // min(right side)

                else{

                    return (
                        max(nums1Left, nums2Left) +
                        min(nums1Right, nums2Right)
                    ) / 2.0;
                }
            }

            // too many elements taken from nums1
            // nums1Left is too large
            // move partition left

            else if(nums1Left > nums2Right){

                right = x - 1;
            }

            // too few elements taken from nums1
            // move partition right

            else{

                left = x + 1;
            }
        }

        return -1;
    }
};