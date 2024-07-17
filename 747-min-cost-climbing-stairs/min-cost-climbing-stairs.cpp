class Solution {
public:
    int array[1001];
    int max_cost(int n,vector<int> &arr)
    {
        if(n<0) return 0;
        if(array[n] !=  -1) return array[n];
        array[n] = arr[n]+min(max_cost(n-1,arr),max_cost(n-2,arr));
        return array[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n=cost.size();
        for(int i=0 ; i<n; i++)    array[i]=-1;
       return max_cost(n-1,cost);
        // return  a;
    }
};