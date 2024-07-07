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
   vector<vector<int>> arr;
   queue<TreeNode*> q;
    void fn(int n,int level=0)
    {
        if(n==0)
            return;
            arr.push_back({});
        TreeNode* root;
        for(int i=0 ; i<n ; i++)
        {
            root=q.front();
            arr[level].push_back(root->val);
            q.pop();
            if(root->left != nullptr)   q.push(root->left);
            if(root->right != nullptr)  q.push(root->right);

        }
        fn(q.size(),++level);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == nullptr)
            return arr;
        q.push(root);
        fn(1);
        return arr;
    
    }
};