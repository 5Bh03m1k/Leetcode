class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> in(n,0);
        vector<vector<int>> al(n);

        for(auto i:p)
        {
            al[i[1]].push_back(i[0]);
            in[i[0]]++;
        }

        queue<int> q;
        int cnt = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(in[i] == 0)  q.push(i);
        }

        while(!q.empty())
        {
            int x = q.front();
            cnt++;

            for(auto i:al[x])
            {
                in[i]--;

                if(in[i] == 0)  q.push(i);
            }

            q.pop();
        }

        return (cnt == n);
    }
};