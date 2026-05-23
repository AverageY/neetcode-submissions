class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        priority_queue<pair<int,int>> pq;
        vector<int> result;

        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        
        for(auto it: mpp){
            pq.push(make_pair(it.second, it.first));
        }

        for(int i=0; i<k; i++){
            int ele = pq.top().second;
            pq.pop();
            result.push_back(ele);
        }

        return result;
    }
};
