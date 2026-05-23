class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        int maxlen = 0;
        for(int i = 0; i<nums.size(); i++){
            if(mpp.find(nums[i]) == mpp.end()){
            mpp[nums[i]] = i;
            }
        }

        // for(int i = 0; i< nums.size(); i++){
        //     int len = 1;
        //     for(int j = 1; j<= nums[i]; j++){
        //         if(mpp[nums[i]-j]){
        //             len+=1;
        //         }
        //         else{
        //             maxlen = max(len, maxlen);
        //         }
        //     }
        // }
            
        for(int i=0; i<nums.size(); i++){
            int len = 1;
            int curr = nums[i];
            if(mpp.find(nums[i]-1) == mpp.end()){
                while(mpp.find(curr+1) != mpp.end()){
                    len++;
                    curr++;

                }
            }
            maxlen = max(len, maxlen);
        }

        return maxlen;
    }
};
