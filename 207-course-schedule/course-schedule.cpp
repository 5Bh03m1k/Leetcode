class Solution {
private:
    bool dfs(vector<vector<int>>&a , int n,vector<bool>&vis , vector<bool>&ic)
    {
        if(vis[n]) return false;
        vis[n] = true;


        for(auto i : a[n])
        {
            if(ic[i] == true && dfs(a,i,vis,ic) == false)   return false;
        }
        ic[n] = false;
        vis[n] = false;
        return true;
    }
public:
    bool canFinish(int s, vector<vector<int>>& p) {
        
        vector<vector<int>> al(s);
        vector<bool> vis(s,false);
        vector<bool> ic(s,true);
    
        for(auto i:p)
            al[i[1]].push_back(i[0]);

        int c = 0;

        for(int i=0 ;i < s ;i++)
        {
            if(ic[i] && dfs(al,i,vis,ic) == false)  return false;
         
        }

        return true;
        
    }
};