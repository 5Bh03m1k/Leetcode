class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        /*unordered_map<int,queue<int>>  ht;

        for(int i = 0 ; i < nums.size() ; i++)
            ht[nums[i]].push(i);*/
        
        vector<pair<int,int>> a;
        vector<int> b;

        for(int i =0 ; i < nums.size();i++)
            a.push_back({nums[i],i});
        
        priority_queue<pair<int,int>> pq(a.begin() , a.end());

        while(k)
        {
            b.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        sort(b.begin() , b.end());

        for(int i = 0 ; i < b.size() ; i++)
            b[i] = nums[b[i]];

        return b;
    }
};