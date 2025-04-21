class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long maxi = INT_MIN , mini = INT_MAX , sum = 0;
        for(auto i:diff)
        {
            maxi = max(maxi , sum);
            mini = min(mini , sum);
            
            sum+=i;
        }

        maxi = max(maxi , sum);
        mini = min(mini , sum);

        int n = (upper - lower) - (maxi - mini) + 1;
        return n > 0?n : 0 ;
    }
};