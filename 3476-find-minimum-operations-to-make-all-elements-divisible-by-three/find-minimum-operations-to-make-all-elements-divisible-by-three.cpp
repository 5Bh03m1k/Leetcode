class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;

        for(auto& i:nums)
            cnt+= i%3 == 0? 0 : 1 ;
        
        return cnt;
    }
};