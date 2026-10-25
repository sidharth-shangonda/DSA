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
    TreeNode* insertNode(TreeNode* root,int key) {
        if(root == nullptr) {
            root = new TreeNode(key);
        } else if(root->val > key) {
            root->left = insertNode(root->left ,key);
        } else if(root->val < key ) {
            root->right = insertNode(root->right,key);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = nullptr;
        // TreeNode *temp = root;
        for(auto key:preorder) {
            root = insertNode(root,key);
        }
        return root;
    }
};