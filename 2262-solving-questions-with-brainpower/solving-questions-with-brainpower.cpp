long long m[100001];
class Solution {

public:
    long long mostPoints(vector<vector<int>>& a) {
        long long maxi = 0;
        for(int i=a.size()-1 ; i>=0 ; i--){
            m[i] = max((a[i][0] + ((i+a[i][1]+1) < a.size()?m[i+a[i][1]+1] : 0)),maxi);
            maxi = m[i];
        }
        return maxi;
    }
};