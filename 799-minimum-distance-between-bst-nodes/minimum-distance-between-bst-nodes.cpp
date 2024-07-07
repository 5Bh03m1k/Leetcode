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
        int min=INT_MAX;
        int val=-1,n;
        int minDiffInBST(TreeNode* root) {
        if(root == nullptr)
            return min;
        minDiffInBST(root->left);
        n=root->val-val;
        if(val != -1)
            min=min>n?root->val-val:min;
        val=root->val;
        minDiffInBST(root->right);
        return min;
    }
};
    
