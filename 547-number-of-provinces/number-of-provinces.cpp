class Solution {
private:
    vector<bool> v;

    void bfs(vector<vector<int>> arr)
    {

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
        vector<bool> n(ic.size(),true);

        for(auto i:ic)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<"\n";
        }
        ////////////////////bfs///////////////////
        for(int i = 0 ; i < n.size() ; i++)
        {
            if(n[i]){
                num++;
                queue<int> q;
                q.push(i);
                n[i] = false;
                while(!q.empty())
                {
                    for(int it = 0 ; it < ic[q.front()].size() ; it++)
                    {
                        int l = ic[q.front()][it];
                        if(n[l] == true)
                        {
                            q.push(l);
                            n[l] = false;
                        }
                    }

                    q.pop();
                }
            }
        }
        /////////////////////////////////////////
        return num;
    }
};