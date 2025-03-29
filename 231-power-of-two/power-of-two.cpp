class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 0)
        {
            if(n & 1)  
            {
                if(n == 1)  return true;
                return false;
            }
            n >>= 1;
        }
        return false;
    }
};