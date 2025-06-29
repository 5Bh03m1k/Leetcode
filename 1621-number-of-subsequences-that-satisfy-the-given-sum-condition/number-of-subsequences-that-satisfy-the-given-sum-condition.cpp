class Solution {
private:
    int mod = 1e9 + 7;

    int po2(int n)
    {
        long int ans = 1,b = 2;

        while( n > 0 )
        {
            if(n%2 )
                ans *= b , ans %= mod;
            b *= b;
            b %= mod;
            n /= 2;
        }

        return ans;
    }

public:
    int numSubseq(vector<int>& nums, int target) {
        long long int ans = 0, a=1;
        vector<int> po2;
        
        for(auto i:nums)
        {
            po2.push_back(a);
            a = a<<1;
            a %= mod;
        }

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(target >= 2*nums[i])
            {
                 auto it = upper_bound(nums.begin(),nums.end(),target - nums[i]);
                 a = it - nums.begin() - i - 1;

                ans += po2[a];
                ans %= mod;

            }
            

        }
        

        return ans%mod;
    }
};