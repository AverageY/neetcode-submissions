#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0 , j = heights.size()-1;
        int maxarea = 0;
        while(i<j){
            int currheight = min(heights[i], heights[j]);
            int distance = j - i;
            int area = currheight*distance;
            maxarea = max(area, maxarea);

            // the reasoning behind this is , when we move either bar, the width is decreased by one
            // so to maximise area , we need to move towards bigger bars
            // if we move the smaller bar, we have a chance to find a taller bar that can compensate for the decrease in width and potentially increase the area
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }

       return maxarea;
    }
};

