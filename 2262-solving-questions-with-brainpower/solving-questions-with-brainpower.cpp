class Solution {
long long maxi = 0;
public:
    long long point(int n,long long map[],vector<vector<int>>& a){
        if(n < 0)  return 0;
        for(int i=n ; i>=0 ; i--){
            map[i] = max((a[i][0] + ((i+a[i][1]+1) < a.size()?map[i+a[i][1]+1] : 0)),maxi);
            maxi = map[i];
        }
        return maxi;
       

    }
    long long mostPoints(vector<vector<int>>& a) {
        long long* map = (long long *)malloc(a.size() * sizeof(long long));
        for(int i=0 ; i<a.size() ; i++) map[i] = 0;
       

        return point(a.size()-1 , map , a);
    }
};