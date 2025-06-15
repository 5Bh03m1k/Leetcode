class Solution {
private:
    void dfs(vector<vector<char>>& g , int x , int y)
    {
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] == 'X' || g[x][y] == '!')   return;

        g[x][y] = '!';

        dfs(g,x-1,y);
        dfs(g,x+1,y);
        dfs(g,x,y-1);
        dfs(g,x,y+1);
    }
public:
    void solve(vector<vector<char>>& g) {
        for(int i = 0 ; i < g.size() ; i++)
        {
            if(g[i][0] == 'O')          dfs(g,i,0);
            if(g[i][g[0].size()-1] == 'O')dfs(g,i,g[0].size()-1);
        }

        for(int i = 0 ; i < g[0].size() ; i++)
        {
            if(g[0][i] == 'O')          dfs(g,0,i);
            if(g[g.size()-1][i] == 'O')dfs(g,g.size()-1,i);
        }

        for(int i = 0 ; i < g.size() ; i++)
        {
            for(int j = 0 ; j < g[0].size() ; j++)
            {
                if(g[i][j] == 'O')  g[i][j] = 'X';
                if(g[i][j] == '!')  g[i][j] = 'O';
            }
        }
    }
};