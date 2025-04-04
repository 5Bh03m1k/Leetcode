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
private:
    list<TreeNode*> dq;
    TreeNode* tmp;
    int h = 0;
public:
    bool ca(TreeNode* root , TreeNode* l , TreeNode* r)
    {
        if( root == nullptr )   return false;
        

        bool tmp1 = ca(root->left , l ,r) , tmp2 = ca(root->right , l ,r);
        if( root == l || root == r){
            if(tmp1 || tmp2) {tmp = root;return false;}
            return true;
        }
        if( tmp1 && tmp2)   {tmp = root;return false;}
        return tmp1 || tmp2;
    }

    void leaf( int d = 1 )
    {
        if(d == h)  return;
        //if(root == nullptr) return;
        int n = dq.size();
       for(int i=0 ; i<n ; i++){
            if(dq.front()->left != nullptr) dq.push_back(dq.front()->left);
            if(dq.front()-> right != nullptr) dq.push_back(dq.front()->right);
            dq.pop_front();
       }
       leaf(d+1);
       return;
        
    }

    int height(TreeNode* root ){
        if(root == nullptr) return 0;
        return max(height( root->left ),height( root->right )) + 1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

       h = height(root);

       dq.push_back(root);
       leaf();
        if(dq.size() == 1)  return dq.front();
        
        ca(root,dq.front(),dq.back());

        return tmp;
    }
};