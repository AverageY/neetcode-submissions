// Most important learning I had from this is about heaps/priority queues
// for top k , either use a max heap and pop k times to get the top k elements
// or use a min heap of size k to maintain the top k elements, as size hits greater than k, pop the least frequent element (top of min heap) to maintain only the top k elements in the heap

// similary for min k frequent elements, we can use a min heap and pop k times to get the least k frequent element
// or use a max heap of size k to maintain the least k frequent elements, as size hits greater than k,
// pop the most frequent element (top of max heap) to maintain only the least k elements in the heap

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        priority_queue<pair<int,int>> pq;
        vector<int> result;

        // we first store frequency in a map

        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }

        // since we want to get top k elements we will use a max heap
        // and we can store a pair of frequency, element so that max heap is ordered by freq highest to lowest
        
        for(auto it: mpp){
            pq.push(make_pair(it.second, it.first));
        }


        // we now iterate over the max heap and get the top k elements and push them in result vector
        for(int i=0; i<k; i++){
            int ele = pq.top().second;
            pq.pop();
            result.push_back(ele);
        }

        return result;
    }

public:
    vector<int> topKFrequentBucketSort(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
       freq[num]++;
    }
    
    //Find the maximum frequency
    int maxFreq = 0;
    for (pair<int,int> entry : freq) {
        maxFreq = max(maxFreq, entry.second);
    }
    
    // Create buckets based on frequencies
     // Each bucket index represents frequency
    vector<vector<int>> buckets(maxFreq + 1); 

    // index is the frequency and value is the list of numbers with that frequency
    for (pair<int,int> entry : freq) {
        buckets[entry.second].push_back(entry.first);
    }
    
    // Collect top k frequent elements
    // since higher frequency is at the end of the buckets we will iterate from the end to the beginning
    // and collect elements until we have k elements in result vector
    // missing frequency buckets will be empty so we can skip them
    vector<int> res;
    for (int i = maxFreq; i >= 1; --i) {
        // go through each bucket and add elements to result vector until we have k elements
        // there can be multiple elements in the same bucket if they have the same frequency
        // so we need to go through all of them , thus an inner loop is needed 
        // empty buckets will be skipped as the iterator (nums: buckets[i]) will not enter the inner loop for those buckets
        for (int num : buckets[i]) {
            res.push_back(num);
            if (res.size() == k) {
                return res;
            }
        }
    }
    
    return res;
    }


public:
    vector<int> topKFrequentMinHeap(vector<int>& nums, int k) {

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create a MIN HEAP
        // We store pairs: {frequency, element}
        // 'greater<>' makes it a min heap (smallest freq on top)

        //min heap is better than max heap for this problem because we want to keep track of the top k elements 
        // and remove the least frequent element when we exceed k
        // max heap will need to rebalance more often as we add new elements and remove the least frequent one, 
        //while min heap will always keep the least frequent element on top for easy removal
        // so we create a min heap that stores pairs of (frequency, element) of size k
        // so that we can easily compare frequencies and maintain the top k elements in the heap by removing the top element (least frequent) when we exceed k
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
            // the order isn't really ascending that top ele is min and then other ele are in ascending order
            // its a binary tree internally that makes sure top element is always min
            // when the element is popped, we get the next min element as the new top of the heap
            // so popping guarantees that we get elements in ascending order, but for this the heap has to partially heapify after every push and pop operation, which is done internally by the priority queue implementation
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

        //result order is not guaranteed
        return result;
    }
};
