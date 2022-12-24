/*
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge 

such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.
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

const int32_t mod=1e9+7;

class Solution {
    unordered_map<TreeNode*,int> dp;

    int getsum(TreeNode* root){
        if(root==NULL)return 0;
        if(dp.find(root)!=dp.end())return dp[root];
        if(root->right==NULL && root->left==NULL)return root->val;
        return dp[root]=root->val + getsum(root->right)+getsum(root->left);
    }


    void inorder(TreeNode* root,vector<int>& v){
        if(root==NULL)return;
        if(root->right==NULL && root->left==NULL){
            v.push_back(root->val);
            return;
        }
        inorder(root->left,v);
        v.push_back(getsum(root));
        inorder(root->right,v);
    }


public:
    int maxProduct(TreeNode* root) {
        int sum=getsum(root);
        vector<int> sums,temp;
        inorder(root,sums);

        for(auto it:sums){
            int p=sum-it;
            // cout<<p<<endl;
            temp.push_back(p);
        }
        for(auto it:temp){
            sums.push_back(it);
        }
        // cout<<"\n";
        int n=sum/2;
        cout<<n<<endl;
        sort(sums.begin(), sums.end());
        int lower= *lower_bound(sums.begin(), sums.end(), n);
        if(lower==sum){
            while(sums.back()==sum)sums.pop_back();
            lower=sums.back();
        }
        int x=sum-lower;

        long long int ans= ((lower*1LL%mod)*(x*1LL%mod))%mod;
        // cout<<ans<<endl;
        return ans;
    }
};