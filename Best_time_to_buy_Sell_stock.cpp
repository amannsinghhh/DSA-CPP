// 3 september 2023
//121. Best Time to Buy and Sell Stock
// LC 121

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

*/

class Solution {
public:
    int maxProfit(vector<int>& arr) {
       int least = INT_MAX;
        int tot_profit = 0;
        int profit_today = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < least){
                least = arr[i];
            }
            profit_today = arr[i] - least;
            if(tot_profit < profit_today){
                tot_profit = profit_today;
            }
        }
        return tot_profit; 
    }
};
