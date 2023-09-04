// 4 September 2023
// 322. Coin Change
// LC 322

/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        long mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            long ans=coinChange(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini, 1+ans);
            }
        }
        return mini;
    }
};
