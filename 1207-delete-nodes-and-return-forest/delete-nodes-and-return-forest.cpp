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
    // TreeNode* trunk;
    unordered_set<int> number;
    vector<TreeNode*> ans;
    queue<pair<TreeNode*,bool>> q;
    void fn(TreeNode* root)
    {
        if(root == nullptr) return;
        fn(root->left);
        fn(root->right);
        if(root->left != nullptr && number.find(root->left->val) != number.end())    q.push({root,false});
        if(root->right !=nullptr && number.find(root->right->val) != number.end())     q.push({root,true});
    }

    void seg()
    {
        if(q.size() == 0) return;
        if(q.front().first == nullptr)    q.pop();
        else if(q.front().second)
        {
            TreeNode* root = q.front().first->right;
            if(root -> left != nullptr) ans.push_back(root->left);
            if(root -> right != nullptr) ans.push_back(root->right);
            q.front().first->right = nullptr;
            q.pop();
            delete root;
        }
        else
        {
            TreeNode* root = q.front().first->left;
            if(root -> left != nullptr) ans.push_back(root->left);
            if(root -> right != nullptr)    ans.push_back(root->right);
            q.front().first->left = nullptr;
            q.pop();
            delete root;
        }
        seg();
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i:to_delete)
            number.insert(i);
        TreeNode* n = new TreeNode;
        bool flag =false;
        if(number.find(root->val) != number.end())
        {
            n->val=-1;
            n->right = nullptr;
            n->left = root;
            flag=true;
        }
        else    ans.push_back(root);
        fn(root);
        if(flag)
            q.push({n,false});
        seg();
        return ans;
    }
};