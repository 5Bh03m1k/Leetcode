class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
    queue<pair<int,int>> q;
    int cnt = 0,x,y;
        for(int i = 0 ; i < g.size() ; i++)
        {
            for(int j = 0 ; j < g[0].size() ; j++)
            {
                if(g[i][j] == '1')
                {
                    q.push({i,j});
                    g[i][j] = '0';
                    while(q.size()){
                            for(int a = -1 ; a <=1 ; a++)
                            {
                                for(int b = -1 ; b <=1 ; b++)
                                {
                                    if(a != 0 && b != 0) continue;
                                    x = q.front().first + a;
                                    y = q.front().second + b;

                                    if(x >= 0 && x < g.size() && y >=0 && y < g[0].size())
                                    {
                                        if(g[x][y] == '1')
                                        {
                                            q.push({x,y});
                                            g[x][y] = '0';
                                        }
                                    }
                                }
                            }
                            q.pop();
                    }
                    cnt++;
                }

            }
        }
        return cnt;
    }
};