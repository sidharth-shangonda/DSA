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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sol;
        stack<TreeNode*> s;
        while(true) {
            if(root) {
                s.push(root);
                root=root->left;
            } else {
                if(s.empty()) break;
                root=s.top();
                s.pop();
                sol.push_back(root->val);
                root=root->right;
            }
        }
        return sol[k-1];
    }
};