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
    deque<int> tree;
    void f(TreeNode* root)
    {
        if(root==nullptr)
            return;
        f(root->left);
        tree.push_back(root->val);
        f(root->right);
        return;
    }
    BSTIterator(TreeNode* root) {
        f(root);
    }
    
    int next() {
        int n=tree.front();
        tree.pop_front();
        return n;
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