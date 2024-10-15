class Solution {
public:
    bool canJump(vector<int>& nums) {
        priority_queue<int> pq;
        pq.push(nums[0]);
        int i=0;
        while(true)
        {
            for( i ; i<=pq.top() ; i++)
               { if( pq.top() >= nums.size()-1) return true;pq.push(nums[i]+i);}
            if(i >= pq.top())   return false;
        }
    }
};