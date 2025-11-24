class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int cnt = 0;

        for(auto& i:nums)
        {
            cnt = cnt<<1;
            cnt += i;

            cnt%= 5;

            res.push_back(cnt == 0);
        }

        return res;
    }
};