class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=0,r=nums.size();
        for(int i=0 ; i<nums.size() ; i++)
            n+=nums[i];
        return (r*(r+1))/2 - n;
    }
};