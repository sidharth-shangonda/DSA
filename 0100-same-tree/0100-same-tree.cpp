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
    //just check evey step is same val and structure 
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if((!root && subRoot) || (root && !subRoot)) return false;
        stack<TreeNode*> s;
        s.push(subRoot);
        s.push(root);
        while(!s.empty()) {
            TreeNode* tempr = s.top();
            s.pop();
            TreeNode* temps = s.top();
            s.pop();
            if(tempr->val != temps->val ) return false;
            if(tempr->right || temps->right) {
                if(!tempr-> right || !temps->right) return false;
                s.push(temps->right);
                s.push(tempr->right);
            }
            if(tempr->left || temps->left) {
                if(!tempr->left || !temps->left) return false;
                s.push(temps->left);
                s.push(tempr->left);
            }
        }
        return true;
    }
};