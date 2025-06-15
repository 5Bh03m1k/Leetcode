class Solution {
private:
    void dfs(vector<vector<int>>&g , int x , int y)
    {
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] == 0) return;

        g[x][y] = 0;

        dfs(g,x-1,y);
        dfs(g,x+1,y);
        dfs(g,x,y-1);
        dfs(g,x,y+1);
    }

public:
    int numEnclaves(vector<vector<int>>& g) {
        for(int i = 0 ; i < g.size() ; i++)
        {
            if( g[i][0] == 1 ) dfs(g,i,0);
            if(g[i][g[0].size()-1] == 1) dfs(g,i,g[0].size()-1);
        } 

        for(int i = 0 ; i < g[0].size() ; i++)
        {
            if( g[0][i] == 1 ) dfs(g,0,i);
            if(g[g.size()-1][i] == 1) dfs(g,g.size()-1,i);
        } 

        int c = 0;

        for(auto i:g)
        {
            for(auto j:i)
                 c += j ? 1 : 0;
        }
        return c ;
    }
};