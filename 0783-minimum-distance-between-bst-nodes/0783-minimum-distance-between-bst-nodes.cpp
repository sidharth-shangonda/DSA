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
    void getMin(TreeNode* root, int &prev, int &minDiff) {
        if(root == nullptr) return ;
        getMin(root->left ,prev,minDiff);
        if(prev != -1) {
            minDiff = min(minDiff,root->val - prev);
        }
        prev = root->val;
        getMin(root->right,prev,minDiff);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* temp = root;
        int minDiff = INT_MAX;
        int prev = -1;
        getMin(temp,prev,minDiff);
        return minDiff;
    }
};