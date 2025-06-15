class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<int,int>> q;

        int count = 0;

        for(int i = 0 ; i < g.size() ; i++)
        {
            for(int j = 0 ; j < g[0].size() ; j++)
            {
                if(g[i][j] == 2)
                {  
                    q.push({i,j});
                    count++;
                }
                if(g[i][j] == 1)
                    count++;
            }
        }

        int x = -1 , cnt = 0;
        while(q.size())
        {
            int sze = q.size();
            for( int k = 0 ; k < sze ; k++){
            int a = q.front().first, b = q.front().second;

            if(a-1 >= 0 && g[a-1][b] == 1) g[a-1][b] = 2,q.push({a-1,b});
            if(b-1 >= 0 && g[a][b-1] == 1) g[a][b-1] = 2,q.push({a,b-1});
            if(a+1 < g.size() && g[a+1][b] == 1) g[a+1][b] = 2,q.push({a+1,b});
            if(b+1 < g[0].size() && g[a][b+1] == 1) g[a][b+1] = 2,q.push({a,b+1});

            q.pop();
            cnt++;
            }
            x++;
        }
        if(count == 0)  return 0;
        //cout<<count;
        return count == cnt?x:-1;
    }
};