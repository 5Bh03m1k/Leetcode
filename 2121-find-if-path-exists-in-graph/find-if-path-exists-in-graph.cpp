class Solution {
private:

bool dfs(int n , vector<vector<int>> &a , int d , vector<bool> &vis)
{
    if(n == d)  return true;
    //if(vis[n] == true) return false;
    vis[n] = true;
    bool flag  = false;

    for(auto i:a[n]){
        if(vis[i] == false)
            flag |= dfs(i,a,d,vis);
    }

    return flag;
}

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int de) {
        vector<vector<int>> aj(n);
        vector<bool> vis(n,false);

        for(auto i:edges)
        {
            aj[i[0]].push_back(i[1]);
            aj[i[1]].push_back(i[0]);
        }

        return dfs(source , aj , de , vis);
    }
};