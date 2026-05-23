class Solution {
public:
    int trap(vector<int>& height) {
        int maxarea=0;
        if (height.size() < 3) return 0;

        vector<int> sizel(height.size(),0);
        vector<int> sizer(height.size(),0);
        sizel[0] = 0;
        sizel[1] = height[0];
        sizer[height.size()-1] = 0;
        sizer[height.size()-2]= height[height.size()-1];
        for(int i = 2; i<height.size(); i++){
            sizel[i] = max(height[i-1],sizel[i-1]);
        }
        for(int j = height.size()-3; j>=0; j--){
            sizer[j] = max(height[j+1], sizer[j+1]);
        }


        for(int i = 1; i<height.size()-1; i++){
            int l = sizel[i];
            int r = sizer[i];
            int area = min(l,r)-height[i];
            if(area<0) area=0;
            maxarea += area;
        }
        return maxarea;
    }
};
