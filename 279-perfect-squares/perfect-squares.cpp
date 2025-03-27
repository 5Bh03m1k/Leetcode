unordered_map<int,int> table;
class Solution {

public:
    int numSquares(int n ) {
        if(n == 0)  return 0;
        if(table.count(n) != 0) return table[n];
        int m = INT_MAX,s=sqrt(n);
        if(s*s == n)    return 1;
        for(int i=s ; i*i>=s ; i--)
            m = min(m,numSquares(n-(i*i))+1);
        table[n] = m;
        return m;
    }
};