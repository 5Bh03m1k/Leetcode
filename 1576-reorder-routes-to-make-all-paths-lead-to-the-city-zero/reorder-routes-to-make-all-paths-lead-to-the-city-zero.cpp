class h_table {
private:
    std::bitset<50000> a; // Use appropriate size
    int s = 0;

public:
    void insert(int n) {
        a.set(n);
        s++;
    }

    void erase(int n) {
        a.reset(n);
        s--;
    }

    bool find(int n) {
        return a.test(n);
    }

    int size()
    {
        return s;
    }
};

class Solution {
private:
int dfs(int n , vector<vector<int>> &a ,vector<bool>&vis ,vector<h_table>&p)
{
    int w = 0;
    vis[n] = true;
    for(int i = 0 ; i < a[n].size() ; i++)
    {
        if(vis[a[n][i]] == false)
        {
            if(p[n].size() && p[n].find(a[n][i]))
                w++;
            w += dfs(a[n][i],a,vis,p);
        }
    }
    return w;
}

public:
    int minReorder(int n, vector<vector<int>>& ed) {
        vector<vector<int>> al(n);
        vector<h_table> p(n);

        vector<bool>vis(n,false);

        for(int i = 0 ; i < ed.size() ; i++)
        {
            al[ed[i][0]].push_back(ed[i][1]);
            al[ed[i][1]].push_back(ed[i][0]);
            p[ed[i][0]].insert(ed[i][1]);
        }
        return dfs(0,al,vis,p);


    }
};