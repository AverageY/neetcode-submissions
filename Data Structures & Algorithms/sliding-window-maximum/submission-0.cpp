class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        //make a max heap to store top k elements
        //we can just keep inserting new numbers as they come
        // pop out the top
        // but if a very big number was earlier a part of window
        // but isnt anymore then top will return that
        // so when doing top(), we can check if the number is even a part of window
        // simplest way to do it is store an index too, if index< current window's left
        // keep popping to clear the heap, once we are in window, top() will again give max of window
        priority_queue<pair<int, int>> pq;
        int l = 0;
        for(int r = 0; r<nums.size(); r++){
            pq.push({nums[r], r});
            while(pq.top().second<l){
                pq.pop();
            
            }
            if(r-l+1==k){
                    ans.push_back(pq.top().first);
                    l++;
                }
            }
        return ans;
    }
};
