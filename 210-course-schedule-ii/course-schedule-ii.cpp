class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> al(n);
        vector<int> in(n,0);

        for(auto i:p)
        {
            al[i[1]].push_back(i[0]);
            in[i[0]]++;
        }

        queue<int> q;
        vector<int> topo;

        for(int i = 0 ; i < n ; i++)
        {
            if(in[i] == 0)  q.push(i);
        }

        while(!q.empty())
        {
            int it = q.front();
            topo.push_back(it);

            for(auto i:al[it])
            {
                in[i]--;
                if(in[i] == 0) q.push(i);
            }

            q.pop();
        }

        if(topo.size() == n)    return topo;
        return {};
    }
};