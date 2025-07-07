class Solution {
private:
    bool dfs(vector<vector<int>>&a , int n,bitset<2000>&vis , bitset<2000>&ic)
    {
        if(vis.test(n)) return false;
        vis.set(n);


        for(int i = 0 ; i < a[n].size() ; i++)
        {
            if(ic.test(a[n][i]) && dfs(a,a[n][i],vis,ic) == false)   return false;
        }
        ic.reset(n);
        vis.reset(n);
        return true;
    }
public:
    bool canFinish(int s, vector<vector<int>>& p) {
        
        vector<vector<int>> al(s);
        bitset<2000>vis;
        bitset<2000> ic;
        ic.set();
    
        for(int i = 0 ; i < p.size() ; i++)
            al[p[i][1]].push_back(p[i][0]);

        int c = 0;

        for(int i=0 ;i < s ;i++)
        {
            if(ic.test(i) && dfs(al,i,vis,ic) == false)  return false;
         
        }

        return true;
        
    }
};