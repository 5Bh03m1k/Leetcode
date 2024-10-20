class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<pair<int , vector<int>>> pq;
        vector<vector<int>> ans;

        for(int i=0 ; i<p.size() ; i++)
             pq.push_back({ p[i][0]*p[i][0] + p[i][1]*p[i][1] , {p[i][0],p[i][1]}});

        sort(pq.begin(),pq.end());
           
        for(int i=0 ; i<k ; i++)
            ans.push_back(pq[i].second);

        return ans;

    }
};