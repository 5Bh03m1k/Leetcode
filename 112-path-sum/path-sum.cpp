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
    bool fn(TreeNode* root,int n,int t)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(root==nullptr)
            return false;
        n+=root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(n==t)
                return true;
            return false;
        }
        return fn(root->right,n,t)||fn(root->left,n,t);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fn(root,0,targetSum);
    }
};