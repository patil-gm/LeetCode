/*
You are given a 0-indexed integer array nums of length n.

The average difference of the index i is the absolute difference between the average of the first 
i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

Note:
The absolute difference of two numbers is the absolute value of their difference.
The average of n elements is the sum of the n elements divided (integer division) by n.
The average of 0 elements is considered to be 0.
*/

class Solution {
public:
    int minimumAverageDifference(vector<int>& arr) {

        vector<long long int> presum;
        long long int sum=0;
        for(auto it:arr){
            sum+=it;
            presum.push_back(sum);
        }
        int n=arr.size();
        int adiff=INT_MAX;
        int ans;
        if(n==1)return 0;
        for(int i=0;i<n-1;i++){
            int avg1= round(presum[i]/(i+1));
            int avg2= round((sum-presum[i])/(n-1-i));
            // cout<<avg1<<" "<<avg2<<endl;
            int diff = abs (avg1-avg2);
            if(diff<adiff){
                ans=i;
                adiff=diff;}
        }
        if(presum[n-1]/n < adiff)return n-1;
        return ans;
    }
};