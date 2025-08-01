class Solution {
private:
void pt(int n,vector<vector<int>>&res)
{
    if(n == 1)  return;

    vector<int> an;
    int x;
    for(int i = 0 ; i <= res.back().size() ; i++)
    {
        x = i == 0 ? 0:res.back()[i-1];
        x += i == res.back().size() ? 0 : res.back()[i];

        an.push_back(x);
    }

    res.push_back(an);

    pt(n-1,res);

}
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        arr.push_back({1});

        pt(numRows,arr);

        return arr;
    }
};