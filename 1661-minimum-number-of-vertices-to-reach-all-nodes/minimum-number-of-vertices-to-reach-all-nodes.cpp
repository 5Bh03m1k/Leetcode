class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> a(n,true);
        vector<int> ans;

        for(int i = 0 ; i < edges.size() ; i++)
            a[edges[i][1]] = false;
        
        for(int i=0 ; i<n ; i++)
        {
            if(a[i])
                ans.push_back(i);
        }
        return ans;
    }
};