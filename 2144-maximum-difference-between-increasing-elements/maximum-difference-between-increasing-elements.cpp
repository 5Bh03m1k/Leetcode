class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int t = -1 , m = nums[0]; 

        for(auto i:nums)
        {
            t = ( m < i ) ? ( ( t < i - m) ? i - m : t ) : t;
            m = m > i ? i : m;
        }

        return t;
    }
};