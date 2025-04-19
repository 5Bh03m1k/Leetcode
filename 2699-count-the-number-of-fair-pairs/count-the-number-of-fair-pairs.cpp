class Solution {
public:
    
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        sort(arr.begin(),arr.end());
        long long sum = 0;
        for(auto i : arr)   cout<<i<<" ";
        cout<<endl;
        for(auto i=arr.begin() ; i!= arr.end(); i++)
        {
            auto it = lower_bound(i+1 , arr.end() , lower - *i);
            auto it1 = upper_bound(i+1 , arr.end() , upper - *i);
            int n = arr.end() - it , b = arr.end() - it1 ;
            cout<<n <<" "<<b<<endl;
            sum += n - b;
        }
        return sum;
    }
};