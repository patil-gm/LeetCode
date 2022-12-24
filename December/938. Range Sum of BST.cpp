/*
Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].
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
    void getele(vector<int> &inorder,TreeNode* root){
        if(root==NULL)return;
        getele(inorder,root->left);
        inorder.push_back(root->val);
        getele(inorder,root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> inorder;
        int ans=0;
        getele(inorder,root);
        // cout<<inorder.size();
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]>=low && inorder[i]<=high)ans+=inorder[i];
        }
        return ans;
    }
};