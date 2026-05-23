class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> sa;
        unordered_map<char, int> sb;
        bool ans;
        for( int i = 0; i< s1.size(); i++){
            sa[s1[i]]++;
            if(i!=s1.size()-1) sb[s2[i]]++;
        }

        
        int l = 0;
        //keep window fixed of size s1
        for( int r = s1.size()-1; r< s2.size(); r++ ){
            //insert newer element on right
            sb[s2[r]]++;

            if (sa == sb) return true; 

            // if maps not equal then remove freq of L and increase left
            // r is increased by loop so size of loop is also fixed
            // and we dynamically reduce freq of left and increase of right every time
            sb[s2[l]]--;
            if (sb[s2[l]] == 0) sb.erase(s2[l]);  // keep maps clean
            l++;
        }
        return false;
    }
};
