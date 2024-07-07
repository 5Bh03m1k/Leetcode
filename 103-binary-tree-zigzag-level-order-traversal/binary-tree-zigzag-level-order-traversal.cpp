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
    vector<vector<int>> arr;
    deque<TreeNode*> dq;
    void push(TreeNode* root,int level)
    {
        if(level%2==0)
        {
            if(root->left != nullptr)
                 dq.push_front(root->left);
             if(root->right != nullptr)
                 dq.push_front(root->right);
        }

        if(level%2==1)
        {
            if(root->right != nullptr)
                 dq.push_back(root->right);
             if(root->left != nullptr)
                 dq.push_back(root->left);
        }

    }
    TreeNode* get_pop(int level)
    {
        TreeNode* a;
        if(level % 2 ==0)
        {
            a=dq.back();
            dq.pop_back();
            arr[level].push_back(a->val);
            return a;
        }
        if(level % 2 ==1)
        {
            a=dq.front();
            dq.pop_front();
            arr[level].push_back(a->val);
            return a;
        }
        return a;
    }
    void fn(int n,int level=0,int max=-1)
    {
        if(n==0)
            return;
        if(max<level)
        {
            max=level;
            arr.push_back({});
        }
        TreeNode* root;
        for(int i=0 ; i<n ; i++)
        {
            root=get_pop(level);
            push(root,level);
        }
        fn(dq.size(),++level);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return arr;
        dq.push_back(root);
        // arr.push_back({});
        fn(1);
        return arr;
        
        
    }
};