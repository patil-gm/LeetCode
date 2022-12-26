/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:

    bool canJump(vector<int>& arr) {
           int n=arr.size();
           int maxreach=0;
           if(n==1)return true;
           if(arr[0]==0)return false;

           for(int i=0;i<n;i++){
               if(i>maxreach)return false;
               maxreach=max(i+arr[i],maxreach);
           }

           return true;
    }
};