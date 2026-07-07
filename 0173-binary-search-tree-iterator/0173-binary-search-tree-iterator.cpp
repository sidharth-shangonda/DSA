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
void inorder(TreeNode* root, queue<int> &q) {
    if(!root) return;
    inorder(root->left,q);
    q.push(root->val);
    inorder(root->right,q);
}
class BSTIterator {
    queue<int> q;
public:
    BSTIterator(TreeNode* root) {
        inorder(root,q);
    }
    
    int next() {
        int top=q.front();
        q.pop();
        return top;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */