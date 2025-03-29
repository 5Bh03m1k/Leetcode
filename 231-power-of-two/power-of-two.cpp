class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 0)
        {
            switch( n&1 ){
                case 1: switch( n ){
                            case 1: return true;
                            default:return false;
                        }
                default:break;
            }
            n >>= 1;
        }
        return false;
    }
};