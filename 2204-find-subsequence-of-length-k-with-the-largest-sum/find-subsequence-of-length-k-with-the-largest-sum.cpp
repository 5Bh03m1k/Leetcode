class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        unordered_map<int,queue<int>>  ht;

        for(int i = 0 ; i < nums.size() ; i++)
            ht[nums[i]].push(i);
        
        vector<int> a , b;

        for(auto i:nums)
            a.push_back(i);
        
        priority_queue<int> pq(a.begin() , a.end());

        while(k)
        {
            int i = ht[pq.top()].front();
            ht[pq.top()].pop();
            b.push_back(i);
            pq.pop();
            k--;
        }

        sort(b.begin() , b.end());

        for(int i = 0 ; i < b.size() ; i++)
            b[i] = nums[b[i]];

        return b;
    }
};