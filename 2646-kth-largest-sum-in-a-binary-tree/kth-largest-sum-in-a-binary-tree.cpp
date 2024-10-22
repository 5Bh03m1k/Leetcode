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
    void fn()
    {
        long long n = q.size() , sum = 0;
        if(n == 0)
            return;
        for( int i=0 ; i < n ; i++ )
        {
            sum += q.front() -> val;
            if(q.front() -> left != nullptr) q.push(q.front() -> left);
            if(q.front() -> right != nullptr) q.push(q.front() -> right);
            q.pop();
        }
        pq.push(sum);
        fn();
        return;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        q.push(root);
        fn();
        if(pq.size() < k)   return -1;
        for(int i=1 ; i<k ; i++)
            pq.pop();
        return pq.top();
        
    }
private:
    priority_queue<long long> pq;
    queue<TreeNode*> q;
};