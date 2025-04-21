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
        if( p.size() == 0 )   return nullptr;

        TreeNode* node = new TreeNode;

        node -> val = p.back();

        if( p.size() ==1 )
        {
            node->left = nullptr;
            node -> right = nullptr;
            return node;
        }
        vector<int> lp , li , ri , rp;
        unordered_set<int> left;
        int i=0;

        for( i = 0 ; in[i] != p.back() ; i++)
            li.push_back(in[i]);

        i++;

        for( ; i<in.size() ; i++)
            ri.push_back(in[i]);

        for(int ct = 0 ; ct<li.size() ; ct++)
            lp.push_back(p[ct]);
        for(int ct = li.size() ; ct<p.size()-1 ; ct++)
            rp.push_back(p[ct]);
        node -> left = fn(lp,li);
        node -> right = fn(rp , ri);
        return node;
        
    }
    TreeNode* buildTree(vector<int>& i, vector<int>& p) {
        return fn(p,i);
    }
};