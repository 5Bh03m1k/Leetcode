class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int re = INT_MIN , me = 0;

        for(int i:nums)
        {
            me = max(me + i , i);
            re = max(re , me);
        }
        return re;
    }
};