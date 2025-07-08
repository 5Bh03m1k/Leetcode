class Solution {
private:
    bool cycle(vector<vector<int>>&al , int n , int prev , bitset<1000>&u , deque<int>&dq)
    {
        if(u.test(n)){
            while(dq.size() > 0)
            {
                if(dq.front() == n) break;

                dq.pop_front();
            }
                return false;
        }

        u.set(n);
        dq.push_back(n);

        for(int i = 0 ; i < al[n].size() ; i++)
        {
            if(al[n][i] != prev && cycle(al,al[n][i],n,u,dq) == false) return false;
        }
        dq.pop_back();
        u.reset(n);

        return true;
    }

    void list(vector<vector<int>> &al , vector<vector<int>> &e)
    {
        for(int i = 0 ; i < e.size() ; i++)
        {
            al[e[i][0]-1].push_back(e[i][1]-1);
            al[e[i][1]-1].push_back(e[i][0]-1);
        }
        return;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int c = 0 , n = edges.size();
        vector<vector<int>> al(n);
        bitset<1000>u;
        deque<int> dq;

        list(al,edges);

        //
        //

        cycle(al,0,-1,u,dq);
        u.reset();
        while(dq.size() > 0 )
        {
            u.set(dq.front());
            cout<<dq.front();
            dq.pop_front();
        }

        for(int i = edges.size() - 1 ; i>= 0 ; i--)
        {
            if(u.test(edges[i][0]-1) && u.test(edges[i][1]-1))
                return {edges[i][0] , edges[i][1]};
        }

        return {2,3};
    }
};