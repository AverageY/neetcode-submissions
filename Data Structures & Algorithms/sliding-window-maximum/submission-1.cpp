class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // things can be removed from both sides in dequeue
        // front will have largest, back will have smallest
        deque<int> dq;   // stores indices
        vector<int> ans;

        for (int r = 0; r < nums.size(); r++) {

            // remove indices outside current window
            // window = [r-k+1 ... r]
            // this is done to remove a very big element from previous window
            // that isnt in queue anymore
            // so we remove them for the current window so that it doesnt come again at front
            // this way front will always have max of current window
            if (!dq.empty() && dq.front() < r - k + 1) {
                dq.pop_front();
            }

            // maintain decreasing order in deque
            //
            // remove all smaller elements from back
            // because current element is higher than them
            //
            // example:
            // [3, 2]
            // current = 5
            //
            // 2 and 3 can never become maximum again
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            // insert current index
            // if this is the max element in dequeue window then 
            // the above step already cleaned up everything smaller
            // at this moment dequeue is empty and r will be only element
            // so r is at front, which is correct

            // if r wasnt the max element in window then pushing it at back is correct
            // max of window is at front still
            // we will store it
            dq.push_back(r);

            // first valid window starts when size becomes k
            if (r >= k - 1) {

                // front always stores max element index
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
