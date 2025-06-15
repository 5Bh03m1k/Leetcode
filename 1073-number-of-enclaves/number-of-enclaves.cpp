class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        int cnt = 0,count = 0;
        queue<pair<int,int>> q;

        for(auto i:g)
        {
            for(auto j:i)
                cnt += j;
        }

        for(int i = 0 ; i < g.size() ; i++)
        {
            if( g[i][0] == 1 ) g[i][0] = 0 , q.push({i,0});
            if(g[i][g[0].size()-1] == 1)  g[i][g[0].size()-1] = 0,  q.push({i,g[0].size()-1});
        } 

        for(int i = 0 ; i < g[0].size() ; i++)
        {
            if( g[0][i] == 1 ) g[0][i] = 0, q.push({0,i});
            if(g[g.size()-1][i] == 1) g[g.size()-1][i] = 0 ,   q.push({g.size()-1,i});
        } 

        count += q.size();

        while(!q.empty())
        {
            int x = q.front().first , y = q.front().second;

           if(x-1 >= 0           && g[x-1][y] == 1) g[x-1][y] = 0 , q.push({x-1,y}) , count++;
           if(x+1 < g.size()     && g[x+1][y] == 1) g[x+1][y] = 0 , q.push({x+1,y}) , count++;
           if(y-1 >= 0           && g[x][y-1] == 1) g[x][y-1] = 0 , q.push({x,y-1}) , count++;
           if(y+1 < g[0].size()  && g[x][y+1] == 1) g[x][y+1] = 0 , q.push({x,y+1}) , count++;

           q.pop();
        }
        cout<<cnt;
        return cnt - count;
    }
};