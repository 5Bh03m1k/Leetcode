/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#pragma GCC optimize("Ofast,unroll-loops") 
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        return root;

    }
};