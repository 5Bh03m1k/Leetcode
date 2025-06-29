class Solution {
private:
    int mod = 1e9 + 7;

public:
    int numSubseq(vector<int>& nums, int target) {
        long long int ans = 0, a=1 , c=0;
        vector<int> arr(nums.size());
        
        for(auto i:nums)
        {
            arr[c] = a;
            a = a<<1;
            a %= mod;
            c++;
        }

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(target >= 2*nums[i])
            {
                 auto it = upper_bound(nums.begin(),nums.end(),target - nums[i]);
                 a = it - nums.begin() - i - 1;

                ans += arr[a];
                ans %= mod;

            }
            

        }
        

        return ans%mod;
    }
};