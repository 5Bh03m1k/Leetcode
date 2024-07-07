class Solution {
public:
    int numWaterBottles(int n, int t,int k=0) {
        if((n+k)<t)
            return n;
        return  n+numWaterBottles((n+k)/t,t,(n+k)%t);
    }
};