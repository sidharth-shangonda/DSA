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
public:
    pair<int,int> helper(TreeNode* root,int &ans) {
        if(root==NULL) return {0,0};
        auto [leftSum,l]=helper(root->left,ans);
        auto [rightSum,r]=helper(root->right,ans);
        int avg=(leftSum+rightSum+root->val)/(l+r+1);
        if(avg==root->val) ans++;
        return {leftSum+rightSum+root->val,l+r+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};