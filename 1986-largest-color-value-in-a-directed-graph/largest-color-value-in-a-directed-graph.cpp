class Solution {
private:
int dfs(vector<vector<int>>&al , vector<bool>&s_tab ,int n,vector<int>&v,vector<int>&mem ,int c,vector<bool>&vis)
    {
        if(s_tab[n])    return -1;
        if(mem[n] != -1)    return mem[n];
        s_tab[n] = true;
        vis[n] = true;
       int m = 0;
        for(auto& i:al[n])
        {
                int k = dfs(al,s_tab,i,v,mem,c,vis);
                if(k == -1) return -1;
                m = max(m,k); 
        }
        mem[n] = (v[n] == c)?m+1:m;
        s_tab[n] = false;
        return mem[n];
    }
public:
    int largestPathValue(string c, vector<vector<int>>& edges) {
        int n = c.size();
        vector<int> in(n,0);
        vector<vector<int>> al(n);

        for(auto& i:edges)
            al[i[0]].push_back(i[1]),in[i[1]]++;

        unordered_map<char,int> table;
        vector<int> v;
        int tmp = 0;
        for(auto& i:c)
        {
            if(table.find(i) == table.end())
            {
                table[i] = tmp;
                tmp++;
            }

            v.push_back(table[i]);
        }
        vector<int> mem(n,-1);
        vector<bool> vis(n,false);
    
        int m = -1;
        vector<bool> s(n,false);

        for(int i=0 ;i<n ;i++)
        {
            if(in[i] == 0){
                for(int it = 0 ; it<tmp ; it++){
                    
                    int k =dfs(al,s,i,v,mem,it,vis);
                    for(int i = 0 ; i < mem.size() ;i++)    mem[i] = -1;
                    if(k == -1) return -1;
                    m = max(k,m);
                }
            }
        }
        
        for(auto i:vis)    
        {
            if(!i)  return -1;
        }
        return m;
    }
};
