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
     bool check(TreeNode *root,TreeNode* subRoot) {
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        int val = subRoot->val;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* temp= s.top();
            s.pop();
            if(temp->val == val && check(temp,subRoot)) return true;
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
        return false;
    }
};