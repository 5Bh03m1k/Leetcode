class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> c={};

        arr.push_back(c);

        unordered_map < int , int> table;

        for(int i = 0 ; i < nums.size() ; i++ )
            table[nums[i]]++;

        for(auto it = table.begin() ; it != table.end() ; it++)
        {
            int n=arr.size();
            for(int i=0 ; i<n ; i++)
            {
                vector<int> h = arr[i];
                for(int j=0 ; j < it->second ; j++)
                {
                    h.push_back(it->first);
                    arr.push_back(h);
                }
            }
        }

        return arr;
    }
};