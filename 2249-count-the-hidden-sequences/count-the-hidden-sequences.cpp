class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long maxi = 0 , mini = 0 , sum = 0;
        for(auto i:diff)
        {
            sum+=i;
            maxi = maxi > sum ? maxi : sum;
            mini = mini > sum ? sum : mini ;
        }

         return ((upper - lower) - (maxi - mini) + 1) < 0 ? 0 :  (upper - lower) - (maxi - mini) + 1 ;
        //return n > 0?n : 0 ;
    }
};