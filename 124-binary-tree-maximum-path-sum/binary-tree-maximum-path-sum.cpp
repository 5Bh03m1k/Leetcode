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
    int maxi=INT_MIN;
    int fn(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int a = fn(root->left);
        int b = fn(root->right);
        maxi = max( max( root->val , root->val + max( ( a + b ) , max( a , b ) ) ) , maxi );
        return max( root->val , root->val + max( 0 , max( a , b ) ) );
    }
    int maxPathSum(TreeNode* root) {
        int a = fn( root );
        return   max( a , maxi );
    }
};