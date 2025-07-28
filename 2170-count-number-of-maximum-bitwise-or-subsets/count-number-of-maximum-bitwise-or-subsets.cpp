class Solution {
    private:
        int o = 0;
        void foor_loop(int it , vector<int>&nums , int n , int &res)
        {
           for(int i = it ; i < nums.size() ; i++)
            {
                if( (n|nums[i]) == o) res++;
                foor_loop(i+1,nums,n|nums[i],res);
            }
        }

    public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = 0;

        for(auto& i:nums)
            o |= i;
        
        foor_loop(0,nums,0,n);

        return n;
    }
};