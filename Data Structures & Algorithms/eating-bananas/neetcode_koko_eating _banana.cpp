#include <iostream>

using namespace std;


//Note that the solution is inefficient and hits tle because canEat tries to simulate the eating
// even tho the simulation correctly gives us whether koko can finish bananas or not
// so it works as a condition check for our binary search, but it is not efficient because it is o(n) and we are doing it log(maxBanana) times, 
//so overall it is o(nlog(maxBanana)) which is not good enough for this problem

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
bool canEat(vector<int> piles, int h, int k) {

    int hours = 0;

    int i = 0;

    //simulate banana eating 
    while(i < piles.size()) {

        if(hours >= h) {
            return false;
        }
        //if less banana in pile then all will be eaten
        // move to next pile
        if(piles[i] <= k) {
            piles[i] = 0;
            i++;
        }
        // if more banana then keep eating and dont move yet
        else {
            piles[i] -= k;
        }

        hours++;
    }
    return true;
}
};
