class Solution {
private:
    vector<bool> v;

    int bfs(vector<vector<int>> ic)
    {
        int num = 0;
        for(int i = 0 ; i < v.size() ; i++)
        {
            if(v[i]){
                num++;
                queue<int> q;
                q.push(i);
                v[i] = false;
                while(!q.empty())
                {
                    for(int it = 0 ; it < ic[q.front()].size() ; it++)
                    {
                        int l = ic[q.front()][it];
                        if(v[l] == true)
                        {
                            q.push(l);
                            v[l] = false;
                        }
                    }

                    q.pop();
                }
            }
        }

        return num;
    }
public:
    vector<vector<int>> al (vector<vector<int>>& m)
    {
        vector<vector<int>> l;
        vector<int> sl;

        for(int i = 0 ; i < m.size() ; i++)
        {
            for(int j = 0 ; j < m.size() ; j++)
            {
                if( i != j && m[i][j])
                    sl.push_back(j);
            }

            l.push_back(sl);

            sl.clear();
        }

        return l;
    }

    int findCircleNum(vector<vector<int>>& ic) {
        ic = al(ic);
        int num = 0;
        for(int i = 0 ; i < ic.size() ; i++)
            v.push_back(true);

        return bfs(ic);
    }
};