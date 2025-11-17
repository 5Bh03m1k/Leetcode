class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = -1 , min = INT_MAX;

        for(auto& i:nums)
        {
            if(i == 1)
            {
                min = cnt >= 0 ?(min > cnt ? cnt : min):min;
                cnt = 0;
            }
            else{
                cnt += cnt >= 0 ? 1 : 0;
            }
        }

        return min >= k;
    }
};