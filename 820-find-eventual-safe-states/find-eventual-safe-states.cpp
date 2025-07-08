class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& al) {
        int n = al.size();  

        vector<int> out(n);
        vector<vector<int>> al_new(n);

        for(int i = 0 ; i < al.size() ; i++)
        {
            out[i] = al[i].size();

            for(auto& j:al[i])
            {
                al_new[j].push_back(i);
            }
        }   

        queue<int> q;
        vector<int> topo;

        for(int i = 0 ; i < n ; i++)
        {
            if(out[i] == 0) q.push(i);
        }

        while(!q.empty())
        {
            int k = q.front();
            topo.push_back(k);

            for(auto& i:al_new[k])
            {
                out[i]--;
                if(out[i] == 0) q.push(i);
            }

            q.pop();
        }

        sort(topo.begin(),topo.end());

        return topo;


    }
};