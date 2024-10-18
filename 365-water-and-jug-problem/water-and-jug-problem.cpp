class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x+y)   return false;
        int n = gcd(x,y);
        if(target%n == 0)   return true;
        return false;
    }
};