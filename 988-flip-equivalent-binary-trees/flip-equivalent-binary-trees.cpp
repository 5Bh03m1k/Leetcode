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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return true;
        
        else if(root1 != nullptr && root2 != nullptr){
            if( root1->val!= root2->val)   return false;

            bool b = flipEquiv(root1->left , root2->left) & flipEquiv(root1->right , root2->right);
           return b | (flipEquiv(root1->right , root2->left) & flipEquiv(root1->left , root2->right));
        }
        else
         return false;
    }
};