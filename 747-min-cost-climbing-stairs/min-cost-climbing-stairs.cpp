class Solution {
public:
    int dp[1001];
    int help(int i,vector<int>& cost){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(help(i+1,cost),help(i+2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=0;i<1001;i++) dp[i]=-1;
        return min(help(0,cost),help(1,cost));
    }
};