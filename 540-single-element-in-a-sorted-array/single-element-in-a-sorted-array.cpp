class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = 0; 

        for(auto i : nums)
            n ^= i;

        return n;
    }
};