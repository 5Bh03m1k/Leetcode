class Solution {
private:
    int cnt(long long int n)
    {
        int c = 0;
        while(n>0)
        {
            c += n&1;
            n = n >> 1;
        }

        return c;
    }
public:
    int makeTheIntegerZero(int a, int b) {
         if(a == 0) return 0;

        long long int n = a , lim = 1ll << 60 , i = 0;

        while(++i)
        {
            n -= b;
            if(n <= 0 )  return -1;
            a = cnt(n);

            if(a == i || (a < i && n != 1))return i;
        }

        return -1;
    }
};