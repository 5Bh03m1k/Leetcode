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
    vector<int> r;
    queue<TreeNode*> q;
    void fn(int n)
    {
        if(n==0)
            return;
        TreeNode* cur;
        for(int i=0 ; i<n ; i++)
        {
            cur=q.front();
            q.pop();
            if(cur->left != nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
            if(i==n-1)
                r.push_back(cur->val);
        }
        fn(q.size());

    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
            return r;
        q.push(root);
        fn(1);
        return r;
    }
};