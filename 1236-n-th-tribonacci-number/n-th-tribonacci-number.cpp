class Solution {
public:
    int table[38] = {0};
    int tribonacci(int n) {
        if(n == 0)  return 0;
        if(n == 1 || n == 2)    return 1;
        if(table[n] != 0 )  return table[n];
        table[n] = tribonacci(n-1)  + tribonacci(n-2) + tribonacci(n-3);
        return table[n];
    }
};