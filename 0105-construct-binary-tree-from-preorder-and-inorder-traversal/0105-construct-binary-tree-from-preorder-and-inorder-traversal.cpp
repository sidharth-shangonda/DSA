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
    TreeNode* build(vector<int> &preorder,vector<int> &inorder,int idx,int st,int end) {
        if(st>end) return NULL;
        int rootVal = preorder[idx];
        TreeNode* root = new TreeNode(rootVal);
        int mid = -1; 
        for(int i = st; i<=end;i++) {
            if(rootVal == inorder[i]) {
                mid = i;
                break;
            }
        }
        if(mid == -1) return nullptr;
        root->left = build(preorder,inorder,idx+1,st,mid-1);
        root->right = build(preorder,inorder,idx + mid - st + 1,mid+1,end);//important property calculate the size of the left sub tree and ad add in index to get the right node value!!!
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,0,preorder.size()-1);
    }
};