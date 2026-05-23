class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int, int> mppf;
        unordered_map<int, int> mppb;
        vector<int> result;

        // forward product from last ele = 1 ( no more ele to multiply)
        mppf[nums.size()-1] = 1;

        //backward product from 0th index is 1
        mppb[0] = 1;

        // to calculate forward multi of an ele
        // the product is next num * forward multi of next num
        // start from the back as forward multi of last ele is known (1)
        for(int i= nums.size()-2 ; i>=0; i--){
            mppf[i] = mppf[i+1]*nums[i+1];
        }
        
        // to calculate backward multi we take prev element and backward multi of prev
        for(int i = 1; i<nums.size();i++){
            mppb[i] = mppb[i-1]*nums[i-1];
        }

        for(int i = 0 ; i<nums.size(); i++){
            result.push_back(mppf[i]*mppb[i]);
        }
    return result;
    }
};
