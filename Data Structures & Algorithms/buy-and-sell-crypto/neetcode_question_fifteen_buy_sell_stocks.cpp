#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = 0;
        for(int i =1; i< prices.size(); i++){
            // try selling everyday in future
            int sell = prices[i];
            if(sell>buy){
                // if sell price is more then calculate profit
                maxProfit = max(maxProfit, sell-buy);
            }
            else{
                // if sell price is less then it can be the buy price for future, so update buy price
                buy = sell;
            }
        }
        return maxProfit;
    }
};
