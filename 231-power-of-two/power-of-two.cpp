class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 0)
        {
            if( n&1 ){
                if(n == 1)  return true;
                goto stop;
            }
            n >>= 1;
        }
        stop:
        return false;
    }
};