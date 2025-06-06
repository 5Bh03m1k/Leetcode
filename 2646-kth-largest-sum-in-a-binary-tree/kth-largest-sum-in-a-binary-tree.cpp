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
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        q.push(root);
        while(!q.empty())
        {
            long long n = q.size() , sum = 0;
            for( int i=0 ; i < n ; i++ )
            {
                sum += q.front() -> val;
                if(q.front() -> left != nullptr) q.push(q.front() -> left);
                if(q.front() -> right != nullptr) q.push(q.front() -> right);
                q.pop();
            }
        if(pq.size() < k)
            pq.push(sum);
        else
        {
            if(sum > pq.top())  
            {
                pq.push(sum);
                pq.pop();
            }
        }
    }
        if(pq.size() < k)   return -1;
        return pq.top();
        
    }
private:
    priority_queue<long long , vector<long long> , greater<long long>> pq;
    queue<TreeNode*> q;
};