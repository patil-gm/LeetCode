/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is 
either directly below or diagonally left/right. 

Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

class Solution {
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp){
            if(j<0 || j>=arr.size())return INT_MAX;
            if(i>=arr.size())return 0;
            if(i==arr.size()-1)return arr[i][j];
            if(dp[i][j]!=-1)return dp[i][j];
            int ans=INT_MAX;
            if(j>=0 && j<arr.size()){
            int x=i,y=j;

            // case 1
            x+=1;
            int temp=solve(x,y,arr,dp);
            if(temp!=INT_MAX)ans =min(ans,arr[i][j]+temp);
            x=i;y=j;

            // case 2
            x+=1;y-=1;
            temp=solve(x,y,arr,dp);
            if(temp!=INT_MAX)ans =min(ans,arr[i][j]+temp);
            x=i;y=j;

            // case 3
            x+=1;y+=1;
            temp=solve(x,y,arr,dp);
            if(temp!=INT_MAX)ans =min(ans,arr[i][j]+temp);
            x=i;y=j;

            }
            return dp[i][j]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int temp=solve(0,i,arr,dp);
            ans=min(ans,temp);
        }

        return ans;
    }
};