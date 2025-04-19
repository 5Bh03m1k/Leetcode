class Solution {
public:
    
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        sort(arr.begin(),arr.end());
        long long sum = 0 , it , it1;
        for(auto i=arr.begin() ; i!= arr.end(); i++)
        {
            it = lower_bound(i+1 , arr.end() , lower - *i) - arr.begin();
            it1 = upper_bound(i+1 , arr.end() , upper - *i) - arr.begin();
            
            sum += it1 - it;
        }
        return sum;
    }
};