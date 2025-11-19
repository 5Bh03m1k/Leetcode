class Solution {
public:
    int findFinalValue(vector<int>& nums, int n) {
       bitset<1001> table;
        for(auto& i:nums)
            table.set(i);

        while(n<1001 && table.test(n))
            n = n<<1;
        
        return n;
    }
};