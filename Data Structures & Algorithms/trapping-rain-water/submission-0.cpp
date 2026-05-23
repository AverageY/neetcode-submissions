class Solution {
public:
    int trap(vector<int>& height) {
        int maxarea=0;
        for(int i = 1; i<height.size()-1; i++){
            int j=i-1 , k = i+1;
            int l = 0, r = 0;
            for (int j = i-1; j>=0; j--){
                if(height[j]>height[i]){
                    l = max(l, height[j]);
                }
            }
            for (int k = i+1; k<=height.size()-1; k++){
                if(height[k]>height[i]){
                    r = max(r, height[k]);
                }
            }
            int area = min(l,r)-height[i];
            if(area<0) area=0;
            maxarea += area;
        }
        return maxarea;
    }
};
