class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int p1=0;
        bitset<10001> table;
        int sum = 0;
        int max = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            while(table.test(nums[i]))
            {
                table.reset(nums[p1]);
                sum -= nums[p1];
                p1++;
            }

            table.set(nums[i]);
            sum += nums[i];
            max = max > sum ? max :sum;
        }

        return max;
    }
};