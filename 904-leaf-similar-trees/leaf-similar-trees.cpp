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
    queue<int> q;
    bool chk(TreeNode* root)
    {
        // if(root -> left == nullptr &&) chk(root->right);
        // if(root -> right == nullptr) chk(root -> left);
        if(root->left == nullptr && root->right == nullptr){
            if(q.size() == 0)   return false;
            int n = q.front();
            q.pop();
            if(n != root->val)  return false;
            return true;
        }

        if(root -> left == nullptr ) return chk(root->right);
        if(root -> right == nullptr) return chk(root -> left);

        return chk(root->left)&chk(root->right);
    }

    void put(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr){
            q.push(root->val);
            return;
        }
        if(root -> left == nullptr ){put(root->right);return;}
        if(root -> right == nullptr) {put(root -> left);return;}
        put(root->left);
        put(root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        put(root1);
        bool a1 = chk(root2);
        if(a1 == false) return false;
       // q.erase();
        put(root2);
        return chk(root2);
    }
};