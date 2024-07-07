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
    int goodNodes(TreeNode* root,int max=INT_MIN) 
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int res=0;
        if(root == nullptr)
            return 0;
        if(root->val>=max)
        {
            res++;
            max=root->val;
        }
        return res+goodNodes(root->left,max)+goodNodes(root->right,max);
        
    }
};