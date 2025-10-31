class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int table[100] = {0};

        for(auto& i:nums)
            table[i]++;

        nums.clear();

        for(int i = 0 ; i < 100 ; i++)
        {
            if(table[i] == 2)
                nums.push_back(i);
        }

        return nums;
    }
};