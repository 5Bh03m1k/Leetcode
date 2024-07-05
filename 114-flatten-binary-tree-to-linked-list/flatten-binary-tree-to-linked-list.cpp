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
    TreeNode* node;
    void fn(TreeNode* root)
    {
        
        if(root->right==nullptr)
        {
            root->right=node->right;
            node->right=nullptr;
            return;
        } 
        fn(root->right);
        return;
    }
    void tr(TreeNode* root)
    {
        if(root==nullptr)
            return;
        TreeNode* tmp = new TreeNode;
        tmp->val=root->val;
        tmp->left=nullptr;
        tmp->right=nullptr;
        node->right=tmp;
        node = tmp;
        tr(root->left);
        tr(root->right);

    }
    void flatten(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr))
            return;
        node=root;
        if(root->left==nullptr && root->right!=nullptr)
        {
            root->left=root->right;
            root->right=nullptr;
        }
       fn(root->left);
       node=root;
       tr(root->left);
       root->left=nullptr;

    }
};