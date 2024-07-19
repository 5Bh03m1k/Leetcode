class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        unordered_set<int> table;
        vector<int> max_table;
         int n=m.size()>m[0].size()? m.size() : m[0].size();
        for(int i=0 ; i<m.size(); i++)
        {
            int min = INT_MAX;
            for(int j=0 ; j<m[0].size() ; j++)
                min = min>m[i][j] ? m[i][j]:min ;
            table.insert(min);
        }
        for(int i=0 ; i<m[0].size(); i++)
        {
            int max=INT_MIN;
            for(int j=0 ; j<m.size() ; j++)
                max = max>m[j][i] ? max:m[j][i];
            if(table.count(max))    max_table.push_back(max);
        }
        return max_table;
    }
};