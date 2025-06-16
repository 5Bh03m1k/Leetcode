class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int t = -1;
        priority_queue<int> pq;
        pq.push(nums[nums.size()-1]);

        for(int i = nums.size()-2 ; i > -1 ; i--)
        {
            if(pq.top() > nums[i])
                t = t > pq.top() - nums[i]? t : pq.top() - nums[i];

            pq.push(nums[i]);
        }

        return t;
    }
};