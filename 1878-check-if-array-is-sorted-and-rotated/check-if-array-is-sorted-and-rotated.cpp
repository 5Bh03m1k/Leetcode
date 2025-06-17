class Solution {
public:
    bool check(vector<int>& nums) {
        bool cnt  = false;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i%nums.size()] > nums[(i+1)%nums.size()])
            {
                if(cnt) return false;
                else    cnt = true;
            }
        }

        return true;
    }
};