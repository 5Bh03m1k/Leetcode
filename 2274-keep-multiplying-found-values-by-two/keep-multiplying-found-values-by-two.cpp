class Solution {
public:
    int findFinalValue(vector<int>& nums, int n) {
        unordered_set<int> table;

        for(auto& i:nums)
            table.insert(i);

        while(table.find(n) != table.end())
            n = n<<1;
        
        return n;
    }
};