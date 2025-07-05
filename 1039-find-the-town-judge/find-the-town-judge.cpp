class Solution {
private:
    // void trust_list(i)
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<pair<int,int>> t(n);

        for(auto i:trust)
        {
            t[i[0]-1].first++;
            t[i[1]-1].second++;
        } 
        int c = 1;
        for(auto i:t)
        {
            if(i.first == 0 && i.second == n-1)    return c;
            c++;
        }

        return -1;
        
    }
};