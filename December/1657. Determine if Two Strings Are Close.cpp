/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>w1;
        unordered_map<char,int>w2;
        
        for(auto it:word1)w1[it]++;
        for(auto it:word2)w2[it]++;
        if(w1.size()!=w2.size())return false;
        // int n=w1.size();
        for(auto it:w1){
            if(w2.find(it.first)==w2.end())return false;
        }
        vector<int> c1,c2;
        for(auto it:w1)c1.push_back(it.second);
        for(auto it:w2)c2.push_back(it.second);
        
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        
        for(int i=0;i<c1.size();i++){
            if(c1[i]!=c2[i])return false;
        }
        
        return true;
    }
};