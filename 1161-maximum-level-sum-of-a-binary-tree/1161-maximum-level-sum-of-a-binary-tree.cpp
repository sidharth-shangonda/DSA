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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root,1});
        int maxSum = INT_MIN;
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            int curLevel = 0;
            for(int i=0;i<size;i++) {
                auto [node,lev] = q.front();
                curLevel = lev;
                q.pop();
                sum += node->val;
                if(node->left) {
                    q.push({node->left,lev+1});
                }
                if(node->right) {
                    q.push({node->right,lev+1});
                }
            }
            if(sum > maxSum ){
                maxSum = sum;
                level = curLevel;
            }
        }
        return level;
    }
};