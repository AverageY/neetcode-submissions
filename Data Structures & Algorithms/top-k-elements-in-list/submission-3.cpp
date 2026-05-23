class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create a MIN HEAP
        // We store pairs: {frequency, element}
        // 'greater<>' makes it a min heap (smallest freq on top)
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>
        > pq;

        // Step 3: Iterate through frequency map
        for (auto it : freq) {

            // Push (frequency, element) into heap
            pq.push({it.second, it.first});

            // If heap size exceeds k, remove smallest frequency
            // This ensures heap always stores top k frequent elements
            if (pq.size() > k) {
                pq.pop(); // removes least frequent element
            }
        }

        // Step 4: Extract elements from heap
        vector<int> result;

        // Heap now contains k most frequent elements
        while (!pq.empty()) {
            result.push_back(pq.top().second); // get element
            pq.pop();
        }

        // Optional: result order is not guaranteed
        return result;
    }
};