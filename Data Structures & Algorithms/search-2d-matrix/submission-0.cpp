class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty() || matrix[0].empty()) return false;


        int n = matrix[0].size();
        int m = matrix.size();

        int left = 0;
        int right = m-1;

        // goal is to first find the correct row and then the correct column inside correct row
        // first do binary search over all rows
        // if target fits between 0 and n-1 of any row then thats the correct row
        // when correct row found, then run an inner binary search 
        // to find target in that row
        while(left<=right){
            int mid = left + (right-left)/2;

            // if target is in the mid row between (mid,0) and (mid,n-1)
            if(target<=matrix[mid][n-1] && target >= matrix[mid][0]){

                // new binary search inside that row
                int innerleft = 0;
                int innerright = n-1;
                while(innerleft<=innerright){
                    int innermid = innerleft + (innerright - innerleft)/2;

                    if(matrix[mid][innermid]==target){
                        return true;
                    }
                    else if(matrix[mid][innermid]>target){
                        innerright = innermid-1;
                    }
                    else{
                        innerleft = innermid+1;
                    }
                }
                // if the inner binary search didnt find the element in possible row
                // then there is no other row where answer can be
                return false;

            }
            else if(target>matrix[mid][n-1]){
                left = mid + 1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
};
