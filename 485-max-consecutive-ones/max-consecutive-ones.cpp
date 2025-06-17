class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int cnt = 0;

        for(auto i : nums)
            cnt = i ? cnt+1 : (m = m > cnt ? m : cnt)*0;

        return max(cnt,m);
    }
};