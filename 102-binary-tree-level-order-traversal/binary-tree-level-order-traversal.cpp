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
    int maxi=-1;
    vector<int>a={};
   vector<vector<int>> arr;
    void fn(TreeNode* root,int i=-1)
    {
        if(root == nullptr)
            return;
        i+=1;
        if(i>maxi)
        {
            maxi=i;
            arr.push_back(a);
        }
        arr[i].push_back(root->val);
        fn(root->left,i);
        fn(root->right,i);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == nullptr)
            return arr;
        fn( root);
        return arr;
    
    }
};