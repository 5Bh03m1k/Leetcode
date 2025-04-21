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
    TreeNode* fn(vector<int>& p , vector<int>& in)
    {
        if(p.size() == 0)   return nullptr;

        vector<int> lp , li , rp , ri;

        TreeNode* node = new TreeNode;

        node -> val = p[0];
        if(p.size() == 1)
        {
            node -> left = nullptr;
            node -> right = nullptr;
            return node;
        }

        int i = 0;
        for(;in[i] != p[0] ; i++)
            li.push_back(in[i]);

        i++;

        for(;i<in.size();i++)
            ri.push_back(in[i]);
        i=1;
        for( int ct = 0 ; ct < li.size() ; ct++ , i++)
            lp.push_back(p[i]);
        
        for( i ; i<p.size() ; i++)
            rp.push_back(p[i]);

        node -> left = fn(lp , li);
        node -> right = fn(rp , ri);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return fn(preorder,inorder);
    }
};