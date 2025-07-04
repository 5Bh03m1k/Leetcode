class Solution {
private:
    vector<vector<int>> adjacency_list(vector<vector<int>>& m)
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

    vector<bool> v;

    void bfs(vector<vector<int>>&ic ,int i , vector<bool>&v)
    {           
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

    void dfs(vector<vector<int>>&ic , int i , vector<bool>&v){

        v[i] = false;

        for(auto it : ic[i])
        {
            if(v[it])
            {
                dfs(ic,it,v);
            }
        }
    }

    int count(vector<vector<int>>&ic, vector<bool>&v)
    {
        int n = 0;
        for(int i = 0 ; i < v.size() ; i++)
        {
            if(v[i])
            {
                n++;
                dfs(ic,i,v);
            }
        }

        return n;
    }

public:
    

    int findCircleNum(vector<vector<int>>& ic) {
        ic = adjacency_list(ic);
        int num = 0;
        vector<bool> v(ic.size(),true);

        return count(ic,v);
    }
};