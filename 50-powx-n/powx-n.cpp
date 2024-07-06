class Solution {
public:
    double myPow(double x,long int n) {
        double res=1;
        x=n<0?(1/x):x;
        n=n<0?-n:n;
        while(n>0)
        {
            res*=(n%2==0?1:x);
            x*=x;
            n=n>>1;
        }
        return res;
    }
};