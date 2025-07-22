class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        queue<int> dq;
        unordered_set<int> table;
        int sum = 0;
        int max = 0;

        for(auto i:nums)
        {
            while(table.find(i) != table.end())
            {
                table.erase(dq.front());
                sum -= dq.front();
                dq.pop();
            }

            dq.push(i);
            table.insert(i);
            sum += i;
            max = max > sum ? max :sum;
        }

        return max;
    }
};