class Solution {
public:
    vector<vector<int>> res;
    vector<int> r;
    int l;
    void solve(int n , int k , int i=1)
    {
        if(k <= 0)  return;
        for(; i<=n-k+1 ; i++)
        {
            r.push_back(i);
            solve(n,k-1,i+1);
            if(r.size() == l)
            res.push_back(r);
            r.pop_back();
        }
        return;

    }
    vector<vector<int>> combine(int n, int k) {
        l=k;
        solve(n,k);
        return res;
    }
};