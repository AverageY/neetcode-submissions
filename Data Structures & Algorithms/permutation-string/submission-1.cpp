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
        for( int r = s1.size()-1; r< s2.size(); r++ ){
            sb[s2[r]]++;
            for(int i=l; i<=r; i++){
                if(sa[s2[i]]!=sb[s2[i]]){
                    ans=false;
                    sb[s2[l]]--;
                    l++;
                    break;
                }
                else{
                    ans = true;
                }
            }
            if(ans==true) return true;

        }
        return false;
    }
};
