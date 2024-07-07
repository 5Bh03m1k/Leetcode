class Solution {
public:
    int numWaterBottles(int n, int t,int k=0) {
        return  (n+k)>=t?(n+numWaterBottles((n+k)/t,t,(n+k)%t)):n;
    }
};