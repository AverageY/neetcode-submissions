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
