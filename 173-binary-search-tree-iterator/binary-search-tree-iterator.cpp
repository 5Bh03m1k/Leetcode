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
class BSTIterator {
public:
    stack<TreeNode*> tree;
    void f(TreeNode* root)
    {
        if(root==nullptr)
            return;
        f(root->right);
        tree.push(root);
        f(root->left);
        return;
    }
    BSTIterator(TreeNode* root) {
        f(root);
    }
    
    int next() {
        TreeNode* n=tree.top();
        tree.pop();
        return n->val;
    }
    
    bool hasNext() {
        if(tree.size()==0)
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */