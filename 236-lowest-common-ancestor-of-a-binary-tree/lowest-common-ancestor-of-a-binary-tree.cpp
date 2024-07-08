/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* find(TreeNode* root,TreeNode* p)
    {
        if(root == nullptr)
            return nullptr;
        if(root == p)
            return root;
        TreeNode* a;TreeNode* b;
        a=find(root->left,p);
        b=find(root->right,p);
        if(a==nullptr && b == nullptr)
            return nullptr;
        else{
            if(a !=nullptr)
                return root->left;
            else
                return root->right;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == nullptr)
            return root;
        TreeNode* a = find(root,p);
        TreeNode* b= find(root,q);
        if(a==root || b==root)  return root;
        if(a==b)   return lowestCommonAncestor(a,p,q);
       return root;
    }
};