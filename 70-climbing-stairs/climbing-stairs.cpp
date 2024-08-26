class Solution {
public:
    int table[45]={0};
    int climbStairs(int n) {
        if(n==1)    return 1;
        if(n==2)    return 2;
        if(table[n-1] != 0) return table[n-1];
        int k = climbStairs(n-1)+climbStairs(n-2);
        table[n-1] = k;
        return k;
    }
};