class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;

        for(int i = 0 ; i < nums.size() ; i++)
            cnt+= nums[i]%3 == 0? 0 : 1 ;
        
        return cnt;
    }
};