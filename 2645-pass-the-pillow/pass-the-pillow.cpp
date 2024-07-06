class Solution {
public:
    int passThePillow(int n, int time) {
        n--;
        int a=time/n,b=time%n;
        switch(a%2)
        {
            case 0: return ++b;
                    break;
            default:return  (n-b)+1;
                    break;
        }
    }
};