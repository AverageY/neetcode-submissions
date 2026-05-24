class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBanana = 0;
        for(int i = 0; i<piles.size(); i++){
            maxBanana = max(maxBanana, piles[i]);
        } 

        int left = 1;
        int right = maxBanana;

        //binary search on answer
        // dont collapse search space
        while(left<right){
            int mid = left + (right-left)/2;

            // this is a valid k, try looking for even lesser k
            // so shrink the range
            // keep right at mid because the shorter range might not work
            // so answer will be at right
            if(canEat(piles, h, mid)){
                right = mid;
            }

            //k is too less, and since mid wasnt answer
            // move left ahead of mid
            else{
                left = mid+1;
            }
        }
        return right;

    }

private:
bool canEat(vector<int>& piles, int h, int k) {

    long long hours = 0;

    // time taken to finish a pile is
    // ceil(pile/k)
    // ceil(pile/k) = (pile+k-1)/k
    for(int pile : piles) {
        hours += (pile + k - 1) / k;
    }

    // if total hours exceed h then she cant finish

    return hours <= h;
}
};
