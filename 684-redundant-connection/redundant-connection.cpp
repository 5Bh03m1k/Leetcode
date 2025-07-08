class Solution {
private:
    bool cycle(vector<vector<int>>&al , int n , int prev , unordered_set<int>&u , deque<int>&dq)
    {
        if(u.find(n) != u.end()){
            while(dq.size() > 0)
            {
                if(dq.front() == n) break;

                dq.pop_front();
            }
                return false;
        }

        u.insert(n);
        dq.push_back(n);

        for(auto i:al[n])
        {
            if(i != prev && cycle(al,i,n,u,dq) == false) return false;
        }
        dq.pop_back();
        u.erase(n);

        return true;
    }

    void list(vector<vector<int>> &al , vector<vector<int>> &e)
    {
        for(auto i:e)
        {
            al[i[0]-1].push_back(i[1]-1);
            al[i[1]-1].push_back(i[0]-1);
        }
        return;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int c = 0 , n = edges.size();
        vector<vector<int>> al(n);
        unordered_set<int> u;
        deque<int> dq;

        list(al,edges);

        //
        //

        cycle(al,0,-1,u,dq);
        u.clear();
        while(dq.size() > 0 )
        {
            u.insert(dq.front());
            cout<<dq.front();
            dq.pop_front();
        }

        for(int i = edges.size() - 1 ; i>= 0 ; i--)
        {
            if(u.find(edges[i][0]-1) != u.end() && u.find(edges[i][1]-1) != u.end())
                return {edges[i][0] , edges[i][1]};
        }

        return {2,3};
    }
};