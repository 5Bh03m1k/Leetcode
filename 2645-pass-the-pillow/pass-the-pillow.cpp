class Solution {
public:
    int passThePillow(int n, int time) {
        n--;
        int a=time/n,b=time%n;
        return a%2==0?b+1:n-b+1;
    }
};