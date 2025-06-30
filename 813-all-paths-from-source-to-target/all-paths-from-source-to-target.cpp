class Solution {
private:
    void dfs(vector<vector<int>> &al , int n , vector<int>&path ,vector<vector<int>>&ans)
    {
        if(n == al.size()-1)
        {
            path.push_back(n);
            ans.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(n);
        for(auto i:al[n])
        {
            dfs(al,i,path,ans);
        }
        path.pop_back();
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;

        dfs(graph,0,path,ans);

        return ans;
    }
};