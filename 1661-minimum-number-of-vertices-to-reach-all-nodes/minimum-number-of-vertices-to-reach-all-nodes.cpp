class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> al(n);
        vector<int> ans;

        for(auto i:edges)
        {
            al[i[1]].push_back(i[0]);
        }
        int c = 0;
        for(auto i:al)
        {
            if(i.size() == 0)   ans.push_back(c);
            c++;
        }

        return ans;
    }
};