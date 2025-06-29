class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long long int ans = 0 ,n;
        int mod = 1e9 + 7;

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(target >= 2*nums[i])
            {
                 auto it = upper_bound(nums.begin(),nums.end(),target - nums[i]);
                 n = it - nums.begin() - i - 1;
                long int aws = 1,b = 2;

                while( n > 0 )
                {
                    if(n%2 )
                        aws *= b , aws %= mod;
                    b *= b;
                    b %= mod;
                    n /= 2;
                }

                ans += aws;
                ans %= mod;

            }
            

        }
        

        return ans%mod;
    }
};