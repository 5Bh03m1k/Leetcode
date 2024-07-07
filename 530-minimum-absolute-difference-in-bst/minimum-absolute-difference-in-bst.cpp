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
    int val=-1;
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr)
            return min;
        getMinimumDifference(root->left);
        if(val != -1)
            min=min>(root->val-val)?root->val-val:min;
        val=root->val;
        getMinimumDifference(root->right);
        return min;
    }
};