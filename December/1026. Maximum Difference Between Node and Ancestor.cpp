/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b 

where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void solve(TreeNode* root,vector<vector<int> >& arr,vector<int>& path){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            path.push_back(root->val);
            arr.push_back(path);
            path.pop_back();
        }
            path.push_back(root->val);
            solve(root->right,arr,path);
            solve(root->left,arr,path);
            path.pop_back();

    }
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<vector<int> >arr;
        vector<int> path;

         solve(root,arr,path);
         int ans=-1;
         for(auto it:arr){
             for(int i=0;i<it.size();i++){
                 for(int j=i+1;j<it.size();j++){
                     int diff=abs(it[i]-it[j]);
                     ans=max(ans,diff);
                 }
             }
         }

         return ans;
    }
};