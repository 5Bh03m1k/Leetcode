class Solution {
private:
    int dfs(vector<vector<int>>& a , int x , int y)
    {
        if( x < 0 || y < 0 || x >= a.size() || y >= a[0].size() || a[x][y] == 0 )   return 0;

        a[x][y] = 0;

        return 1 + dfs(a,x-1,y) + dfs(a,x+1,y) + dfs(a,x,y-1) + dfs(a,x,y+1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int t = 0 , x, y , s = 0;
        queue<pair<int,int>> q;

        for(int i = 0 ; i < g.size() ; i++)
        {
            for(int j = 0 ; j < g[0].size() ; j++)
            {
                //s=max(dfs(g,i,j),s);
                if(g[i][j])
                {
                    q.push({i,j});
                    t++;

                    while(!q.empty())
                    {
                        x = q.front().first , y = q.front().second;
                        g[x][y] = 0;

                        if(x-1 >= 0          && g[x-1][y])  q.push({x-1,y}) , t++ , g[x-1][y] = 0;
                        if(y-1 >= 0          && g[x][y-1])  q.push({x,y-1}) , t++ , g[x][y-1] = 0;
                        if(x+1 < g.size()    && g[x+1][y])  q.push({x+1,y}) , t++ , g[x+1][y] = 0;
                        if(y+1 < g[0].size() && g[x][y+1])  q.push({x,y+1}) , t++ , g[x][y+1] = 0;

                        q.pop();
                    }
                    cout<<t<<" ";
                    s = max(s,t);

                    t = 0;
                }
            }
        }

        return s;
    }
};