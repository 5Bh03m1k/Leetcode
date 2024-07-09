class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=0;
        for(int i=0 ; i<=nums.size() ; i++)
            n^=i;
        for(int i=0 ; i<nums.size() ; i++)
            n^=nums[i];
        return n;
    }
};