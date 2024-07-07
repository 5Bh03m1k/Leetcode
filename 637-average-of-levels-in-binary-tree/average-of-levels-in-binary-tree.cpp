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
    vector<double> ans;
    vector<int> n;
    int max=-1;
    void fn(TreeNode* root ,int i=0)
    {
        if(root == nullptr)
            return;
        if(i>max)
        {
            max=i;
            ans.push_back(root->val);
            n.push_back(1);
        }
        else
        {
            ans[i]+=root->val;
            n[i]++;
        }
        fn(root->left,i+1);
        fn(root->right,i+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==nullptr)   return ans;
        fn(root);
        for(int i=0;i<=max;i++)
            ans[i]/=n[i];
        
        return ans;
    }
};