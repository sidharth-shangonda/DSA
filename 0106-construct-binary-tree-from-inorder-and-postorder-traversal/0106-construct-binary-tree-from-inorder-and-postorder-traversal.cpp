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
    TreeNode* tree(vector<int>& inorder,int iStart,int iEnd, vector<int>& postorder,int pEnd) {
        if(iStart>iEnd) return NULL;
        int rootNode = postorder[pEnd];
        TreeNode* root=new TreeNode(rootNode);
        int i=0;
        for(i=iStart;i<=iEnd;i++) {
            if(rootNode==inorder[i]) break;
        }
        int rightSize = iEnd - i;
        root->right=tree(inorder,i+1,iEnd,postorder,pEnd-1);
        root->left=tree(inorder,iStart,i-1,postorder,pEnd-rightSize-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return tree(inorder,0,n-1,postorder,n-1);
    }
};