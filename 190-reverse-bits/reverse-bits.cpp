class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev=0,i;
        for(int i=0;i<32;i++)
        {
            rev=rev<<1;
            rev+=n%2;
            n=n>>1;
        }
        return rev;
    }
};