class Solution {
public:
    int maxProduct(vector<int>& n) {
        priority_queue<int> q(n.begin() , n.end());
        int x=q.top();
        q.pop();
        return (x-1)*(q.top()-1);
    }
};