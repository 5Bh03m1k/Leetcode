class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int cnt = 0;

        for(auto i : nums)
        {
            if(i)   cnt++;
            else    m = max(cnt,m),cnt = 0;
        }

        return max(cnt,m);
    }
};