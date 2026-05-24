class TimeMap {
public:
    // to store multiple timestamps per key,vaue pair
    // the value must be a vector
    unordered_map<string, vector<pair<int, string>>> mpp;

    TimeMap() {
    }
    
    // keep pushing back to the key, this way a key can have
    // multiple timestamps + values;
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
        
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()){
            return "";
        }
        
        // for this key we have a vector
        // to find timestamp>=timestamp_prev
        // we run a binary search on this vector
        int left = 0;
        int right = mpp[key].size()-1;

        // to store the result
        string res = "";
        vector<pair<int,string>>& vec = mpp[key];

        while(left<=right){
            int mid = left + (right-left)/2;
            //return if found exact
            if(vec[mid].first == timestamp){
                return vec[mid].second;
            }

            // to large, we need timestamp_prev<=timestamp
            // cut down right
            if(vec[mid].first>timestamp){
                right = mid-1;
            }

            // if timestamp_prev<timestamp found
            // store it and try to search for a larger timestamp_prev
            // by cutting down left
            // it at any point left goes further enought that answer is lost
            // the answer is already saved in res
            // also that point is when left>right so loop will break
            else{
                res = vec[mid].second;
                left=mid+1;
            }
        }
        return res;
    }
};
