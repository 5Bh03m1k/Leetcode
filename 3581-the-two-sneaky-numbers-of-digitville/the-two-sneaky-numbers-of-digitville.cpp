class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> table;

        for(auto& i:nums)
            table[i]++;

        nums.clear();

        for(auto&it:table)
        {
            if(it.second == 2)
                nums.push_back(it.first);
        }

        return nums;
    }
};