class Solution {
public:
    int table[101][101]={0};
    int uniquePaths(int m, int n) {
        // int x=0;x
        if(m==1 && n==1)    return 1;
        if(table[m][n] != 0)   return table[m][n];
        if(n==1)    return table[m][n] = uniquePaths(m-1,n);
        if(m==1)    return table[m][n] = uniquePaths(m,n-1);
        return table[m][n] =(uniquePaths(m,n-1)+uniquePaths(m-1,n));
    }
};