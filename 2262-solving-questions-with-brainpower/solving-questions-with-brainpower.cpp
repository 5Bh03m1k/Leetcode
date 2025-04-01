class Solution {

public:
    long long mostPoints(vector<vector<int>>& a) {
        vector<long long> map(a.size());
       long long maxi = 0;
        for(int i=a.size()-1 ; i>=0 ; i--){
            map[i] = max((a[i][0] + ((i+a[i][1]+1) < a.size()?map[i+a[i][1]+1] : 0)),maxi);
            maxi = map[i];
        }
        return maxi;
    }
};