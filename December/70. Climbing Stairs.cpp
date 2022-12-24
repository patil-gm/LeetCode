/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:

    int climbStairs(int n) {
     vector<int> dp(n+1);
     dp[0]=0;
    if(n==1)return dp[1]=1;
    if(n==2)return dp[2]=2;
    dp[1]=1;dp[2]=2;
     for(int i=3;i<=n;i++){
         dp[i]=dp[i-1]+dp[i-2];
     }
     return dp[n];
    }
};