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
    int n=0;
    
    int height(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int a=height(root->left),b=height(root->right);
        return 1+(a>b?a:b);
    }
    vector<vector<int>> fn(vector<vector<int>>arr,TreeNode* root,int i=-1)
    {
        if(root == nullptr)
            return arr;
        i+=1;
        arr[i].push_back(root->val);
        cout<<root->val;
        arr=fn(arr,root->left,i);
        arr=fn(arr,root->right,i);
        return arr;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
         n=height(root);
        vector<vector<int>> arr(n);
        if(root == nullptr)
            return arr;
        arr=fn(arr, root);
        return arr;
    }
};