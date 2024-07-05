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
    int sum=0;
    void fn(TreeNode* root,int n=0)
    {
        if(root==nullptr)
            return;
        
        n*=10;
        n+=root->val;
        if(root->left==nullptr && root->right == nullptr)
        {
            sum+=n;
            return;
        }
        fn(root->left,n);
        fn(root->right,n);
        return;
    }

    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
            return 0;
        fn(root);
        return sum;
    }
};