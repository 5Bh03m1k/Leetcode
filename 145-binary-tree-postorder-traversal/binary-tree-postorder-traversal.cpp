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
    vector<int> fuck;
    void fn(TreeNode* root)
    {
        if(root == nullptr) return;
        fn(root->left);
        fn(root->right);
        fuck.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        fn(root);
        return fuck;
    }
};