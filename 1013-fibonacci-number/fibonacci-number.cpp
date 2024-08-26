class Solution {
public:
    int table[31] = {0};
    int fib(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
       if (table[n] != 0)   return table[n];
       table[n] = fib(n-1) + fib(n-2);
       return table[n];
    }
};