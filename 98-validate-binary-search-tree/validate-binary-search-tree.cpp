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
    ////gambling algo//////
    int val=rand(),n=val;
    bool flag=true,flag1=true;
    void fn(TreeNode* root)
    {
        if(root == nullptr)
            return;
        fn(root->left);
        if(val==n)
            val=root->val;
        else if(val>=root->val)
            flag=false;
        else
            val=root->val;
        fn(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
         fn(root);
        return flag;
        
    }
};