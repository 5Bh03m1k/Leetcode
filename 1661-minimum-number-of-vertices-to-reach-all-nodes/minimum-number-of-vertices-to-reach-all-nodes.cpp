class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bitset<100000> a;
        vector<int> ans;

        for(int i = 0 ; i < edges.size() ; i++)
            a.set(edges[i][1]);
        
        for(int i=0 ; i<n ; i++)
        {
            if(a.test(i) == false)
                ans.push_back(i);
        }
        return ans;
    }
};