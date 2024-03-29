/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
    int solve(int idx,int buy,vector<int> &prices, vector<vector<int>> &dp){
        if(idx>=prices.size())return 0;
    
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        if(buy==1){
            return dp[idx][buy]=max(-prices[idx] + solve(idx+1,0,prices,dp), 
                        0+solve(idx+1,1,prices,dp));
        }

        return dp[idx][buy]=max(prices[idx]+ solve(idx+2,1,prices,dp),
                    0+ solve(idx+1,0,prices,dp));

    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};