class Solution {
public:
    int smallestNumber(int n) {
        int k = 1;
        while(n>k)
        {
            k = 2*k + 1;
        }

        return k;
    }
};