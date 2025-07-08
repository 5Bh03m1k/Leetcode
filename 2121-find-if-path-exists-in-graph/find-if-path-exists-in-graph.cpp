class Solution {
private:

bool dfs(int n , vector<vector<int>> &a , int d , vector<bool> &vis)
{
    if(n == d)  return true;
    //if(vis[n] == true) return false;
    vis[n] = true;
    bool flag  = false;

    for(int i = 0 ; i < a[n].size() ; i++){
        if(vis[a[n][i]] == false)
            flag |= dfs(a[n][i],a,d,vis);
    }

    return flag;
}

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int de) {
        vector<vector<int>> aj(n);
        vector<bool> vis(n,false);

        for(int i = 0 ; i < edges.size() ; i ++)
        {
            aj[edges[i][0]].push_back(edges[i][1]);
            aj[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(source , aj , de , vis);
    }
};