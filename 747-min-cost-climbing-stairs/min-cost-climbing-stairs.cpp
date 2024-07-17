class Solution {
public:
    vector<int> arr;
    int array[1001];
    int max_cost(int n)
    {
        if(n<0) return 0;
        if(array[n] !=  -1) return array[n];
        array[n] = arr[n]+min(max_cost(n-1),max_cost(n-2));
        return array[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        arr = cost;
        arr.push_back(0);
        for(int i=0 ; i<1001 ; i++)    array[i]=-1;
       int a= max_cost(arr.size()-1);
        return  a;
    }
};