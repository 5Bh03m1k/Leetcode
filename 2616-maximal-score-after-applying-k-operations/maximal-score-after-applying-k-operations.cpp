class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq(nums.begin() , nums.end());
        long long sum = 0;
        // for(int i=0 ; i < nums.size() ; i++)
        //     pq.push(nums[i]);
        for(int i=0 ; i < k ; i++)
        {
            long long n = pq.top();
            sum += n ;
            n = n%3 == 0 ? n/3 : n/3 + 1;
            pq.pop();
            pq.emplace(n);
        }
        return sum;
    }
};