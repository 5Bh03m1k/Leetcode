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
    TreeNode* fn(vector<int>& arr , int left , int right)
    {
        if(left > right)   return nullptr;
        // if(left == right)   return nullptr;
        TreeNode* node = new TreeNode;
        cout<<"fuck";
        int n = (left + right)/2;
        node -> val = arr[n];
        node -> left = fn(arr , left , n-1);
        node -> right = fn(arr , n +1, right);
    
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return fn(nums , 0 , nums.size() -1 );


    }
};