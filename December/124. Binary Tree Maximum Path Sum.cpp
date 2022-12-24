/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 

A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
    int postorder(TreeNode* root,int& ans){
        if(!root)return 0;
        if(root->left==NULL && root->right==NULL){
            ans=max(ans,root->val);
            return root->val;
        }
        // cout<<root->val<<" "<<ans<<endl;
        postorder(root->left,ans);
        postorder(root->right,ans);

        int temp=root->val;

        if(root->left && root->right){
           if(root->left->val>0) temp+=root->left->val;
           if(root->right->val>0)temp+=root->right->val;

           int t2= max(root->left->val, root->right->val);
           if(t2>0) root->val=root->val+t2;
        }
        else if(root->left){
           if(root->left->val>0) temp+=root->left->val;
             if(root->left->val>0)root->val+=root->left->val;
        }
        else if(root->right){
            if(root->right->val>0)temp+=root->right->val;
            if(root->right->val>0)root->val+=root->right->val;
        }
        ans=max(temp,ans);
        return ans;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        return postorder(root,ans);
    }
};