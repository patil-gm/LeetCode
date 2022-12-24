/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. 
Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that 
exactly one of the tilings has both squares occupied by a tile.
*/

const int32_t mod=1e9+7;
class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(n+1,0);
        if(n<=2)return n;
        if(n==3)return 5;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;

        long long ans=0;
        for(int i=4;i<=n;i++){
            ans=2*dp[i-1]+dp[i-3];
            ans%=mod;
            dp[i]=ans;
        }

        return dp[n];
    }
};