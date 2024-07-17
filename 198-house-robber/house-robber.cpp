class Solution {
public:
    vector<int> house;
    int dp[100];
    int fn(int n,int size)
    {
        if(n>=size) return 0;
        if(n==size-1)  return house[n];
        if(dp[n] != -1) return dp[n];
        int max=INT_MIN;
        for(int i = n+2 ; i<size ; i++) {  
            int a=fn(i,size)+house[n];
            max=max>a?max:a;
        }
        dp[n] = house[n]>max?house[n]:max;
        return dp[n];
    }
    int rob(vector<int>& nums) {
        house=nums;
        int n=nums.size(),max=INT_MIN;
        for(int i=0 ; i<100 ; i++)    dp[i]=-1;
        for(int i=0 ; i<n ; i++){
           int a=fn(i,n); 
           cout<<a<<"\n";
           max=max>a?max:a;
        }
        return max;   
    }
};