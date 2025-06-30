class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> table;
        int r = 0 , tmp;

        for(auto i:nums)
            table[i]++;

        for(auto it = table.begin() ; it != table.end() ; it++)
        {
            if(table.find(it->first + 1) == table.end())
            {
                if(table.find(it->first - 1) == table.end())
                    continue;
                
                else
                    tmp = table[it-> first -1];
            }

            else{
                if(table.find(it->first - 1) == table.end())
                    tmp = table[it-> first + 1];

                else
                    tmp = max(table[it-> first + 1],table[it-> first - 1]);
            }
            
            r = max(tmp + it->second , r);
        }
        
        return r;
    }
};