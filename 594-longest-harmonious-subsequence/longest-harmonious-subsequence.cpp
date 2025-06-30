class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> table;
        int r = 0 , tmp;

        for(auto i:nums)
            table[i]++;

        for(auto it = table.begin() ; it != table.end() ; it++)
        {

            tmp = (!table.count(it->first + 1) && !table.count(it -> first - 1))? -it->second : (!table.count(it->first+1) ? table[it->first -1] : (!table.count(it->first-1)?table[it->first+1]:max(table[it-> first + 1],table[it-> first - 1])));
            
            
            r = max(tmp + it->second , r);
        }
        
        return r;
    }
};