/*
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        int n=s.length();
        for(int i=0;i<n;i++){
            map[s[i]]++;
        }
        vector<pair<int,char>> arr;
        for(auto it:map){
            arr.push_back({it.second,it.first});
        }
        
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        
        string ans="";
        for(auto it:arr){
            for(int i=0;i<it.first;i++){
                ans+=it.second;
            }
        }
        return ans;
    }
};