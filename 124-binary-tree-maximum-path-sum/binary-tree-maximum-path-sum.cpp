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
    int max=INT_MIN;
    int fn(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int a = fn(root->left);
        int b = fn(root->right);
        int c = a + b;
        c = c > ( a > b ? a : b) ?  c : ( a > b ? a : b);
        c = root->val > ( c + root->val) ? root->val : ( c + root->val );
        max = max > c ? max : c;
        c=0;
        c = c > ( a > b ? a : b) ?  c : ( a > b ? a : b);
        c = root->val > ( c + root->val) ? root->val : ( c + root->val );
         return c;
    }
    int maxPathSum(TreeNode* root) {
        int a = fn( root );
        return   max > a ? max : a;
    }
};