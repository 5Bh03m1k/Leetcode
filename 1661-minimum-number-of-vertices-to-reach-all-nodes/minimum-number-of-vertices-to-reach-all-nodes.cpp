class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> a(n,0);
        vector<int> ans;

        for(int i = 0 ; i < edges.size() ; i++)
            a[edges[i][1]] = 1;
        
        for(int i=0 ; i<n ; i++)
        {
            if(a[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};