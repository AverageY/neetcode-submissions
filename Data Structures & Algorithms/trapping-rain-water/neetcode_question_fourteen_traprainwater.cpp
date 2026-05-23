#include <iostream>
using namespace std;


// intuition is that the water at any spot is trapped by the largest bar on the left and the largest bar on the right.
// And the water there is minimum of height of both side  - height of the current bar
// and the width is 1, so area is just the height of water at that spot 
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

public:
    int trapRainOptimised(vector<int>& height) {
        int maxarea=0;
        if (height.size() < 3) return 0;

        // in the above solution we were recalculating max left and right height everytime for every bar
        // to optimise this we can precompute the max left and right height for every bar and store it in two arrays
        // so at any bar we can just look up the max left and right height in O(1) time and calculate the area

        vector<int> sizel(height.size(),0);
        vector<int> sizer(height.size(),0);
        sizel[0] = 0;
        sizel[1] = height[0];
        sizer[height.size()-1] = 0;
        sizer[height.size()-2]= height[height.size()-1];

        // sizel[i] will store the maximum height of the bar to the left of the current bar (excluding itself)
        // check with immediate left bar and the maximum height of the left bar of the previous bar
        // this will give us the maximum height of the bar to the left of the current bar
        // because if the immediate left bar is taller than the maximum height of the left bar of the previous bar
        // then the immediate left bar will be the maximum height of the left bar for the current bar
        for(int i = 2; i<height.size(); i++){
            sizel[i] = max(height[i-1],sizel[i-1]);
        }

        //sizer[i] will store the maximum height of the bar to the right of the current bar (excluding itself)
        // check with immediate right bar and the maximum height of the right bar of the next bar
        // this will give us the maximum height of the bar to the right of the current bar
        // because if the immediate right bar is taller than the maximum height of the right bar of the next bar
        // then the immediate right bar will be the maximum height of the right bar for the current bar
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

