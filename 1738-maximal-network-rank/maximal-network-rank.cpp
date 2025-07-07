class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> r(n,0);
        vector<int>sr(n);
        vector<unordered_set<int>> al(n);

        for(auto i:roads)
        {
            al[i[0]].insert(i[1]);
            al[i[1]].insert(i[0]);
            r[i[1]]++;
            r[i[0]]++;
        }

        int m = -1;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                m = max(m,al[i].find(j) != al[i].end() ? r[i] + r[j] -1 : r[i] +r[j]);
            }
        }

        return m;
    }
};