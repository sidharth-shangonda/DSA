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
    TreeNode* insertBST(TreeNode* root,int key) {
        if(!root) return new TreeNode(key);
        if(root->val>key) root->left=insertBST(root->left,key);
        else if(root->val<key) root->right=insertBST(root->right,key);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(auto key:preorder) {
            root=insertBST(root,key);
        }
        return root;
    }
};