class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int t = -1;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i+1 ; j < nums.size() ; j++)
                t = max(t , (nums[i] < nums[j] ? nums[j]-nums[i]:-1));
        }

        return t;
    }
};