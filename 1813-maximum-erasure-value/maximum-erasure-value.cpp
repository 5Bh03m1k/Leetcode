class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int p1=0;
        unordered_set<int> table;
        int sum = 0;
        int max = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            while(table.find(nums[i]) != table.end())
            {
                table.erase(nums[p1]);
                sum -= nums[p1];
                p1++;
            }

            table.insert(nums[i]);
            sum += nums[i];
            max = max > sum ? max :sum;
        }

        return max;
    }
};