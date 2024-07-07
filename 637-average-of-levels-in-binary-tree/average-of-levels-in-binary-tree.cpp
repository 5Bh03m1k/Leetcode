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
     vector<double> arr;
     queue<TreeNode*> q;
    void fn(int n,int j=0)
    {
        if(n == 0)
            return;
        arr.push_back(0);
        for(int i=0 ; i<n ; i++)
        {
            if(q.front()->left != nullptr) q.push(q.front()->left);
            if(q.front()->right != nullptr) q.push(q.front()->right);
            arr[j]+=q.front()->val;
            q.pop();
        }
        arr[j]/=n;
        fn(q.size(),++j);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root==nullptr)   return arr;
        q.push(root);
        fn(1);
        return arr;
    }
};