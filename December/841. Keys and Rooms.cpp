/*
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks,
 and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
return true if you can visit all the rooms, or false otherwise.
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<rooms[curr].size();i++){
                if(visited[rooms[curr][i]]==0){
                    q.push(rooms[curr][i]);
                    visited[rooms[curr][i]]=1;
                }
            }
        }

        for(auto it:visited){
            if(it==0)return false;
            // cout<<it<<" ";
        }

        return true;
    }
};