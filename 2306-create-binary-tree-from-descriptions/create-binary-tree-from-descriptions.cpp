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
    TreeNode* create(int n)
    {
        TreeNode* root = new TreeNode;
        root->val = n;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    void connect(TreeNode* root1 , TreeNode* root2 , int n)
    {
        switch(n)
        {
            case 1:root1->left = root2;
                    break;
            default:root1->right = root2;
                    break;
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        unordered_map<int,TreeNode*> table;
        TreeNode* start = nullptr;
        for(int i=0 ; i<arr.size() ; i++)
        {
            if(table.count(arr[i][0])==0)
            {
                TreeNode* root=create(arr[i][0]);
                table[arr[i][0]]=root;
            }

            if(table.count(arr[i][1])==0)
            {
                TreeNode* root=create(arr[i][1]);
                table[arr[i][1]]=root;
            }
                
           connect(table[arr[i][0]],table[arr[i][1]],arr[i][2]);
        }
        unordered_set<TreeNode*> rev;
        for(auto it = table.begin() ; it != table.end() ; it++)
        {
            if(it->second->left != nullptr) rev.insert(it->second->left);
            if(it->second->right != nullptr) rev.insert(it->second->right);
        }
        for(auto itr = table.begin() ; itr != table.end() ; itr++)
            if(rev.find(itr->second) == rev.end())  return itr->second;
        return start;
    }
};