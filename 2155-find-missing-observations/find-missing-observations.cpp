typedef  long long ll;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        ll sum = mean * ( n + rolls.size() );
        for(int i=0 ; i<rolls.size() ; i++) sum-=rolls[i];
        if(sum < n || 6*n < sum)    return ans;
        ll avg = sum/n ;
        ll diff = sum - avg*n;
        for(int i=0 ; i<n ; i++ ) ans.push_back(avg);
        for(int i = ans.size()-1 ; diff>0 ; i--)
        {
            if( diff <= (6-avg) )
            {   ans[i]+=diff;
                break;
            }
                ans[i] = 6 ;
                diff -= 6-avg ;
        }
        return ans;

    }
};