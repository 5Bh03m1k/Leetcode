class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size() == 1)    return true;
        for(int i=0 ; i<nums.size();i++)
            nums[i]+=i;
        int n;
        priority_queue<int> pq;
        pq.push(nums[0]);
        while(true)
        {
            int i=0;
            for( i ; i<=pq.top() ; i++)
               { if( pq.top() >= nums.size()-1) return true;pq.push(nums[i]);}
            cout<<pq.top()<<i;
            if(i >= pq.top())   return false;
            // if( pq.top() >= nums.size()-1) return true; 
        }
    }
};