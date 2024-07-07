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
    int itr,val;
    void fn(TreeNode* root)
    {
        if(root == nullptr)
            return;
        fn(root->left);
        if(itr==0)
            return;
        itr--;
        if(itr == 0)
            val=root->val;
        fn(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)
            return 0;
            itr=k;
        fn(root);
        return val;
    }
};