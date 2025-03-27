class Solution {
public:
    bool is_perfect(int n)
    {
        //int s = sqrt(n);

        if(int(sqrt(n))*int(sqrt(n)) == n)    return true;
        return false;
    }

    int numSquares(int n) {
        //////////langrage 4 square theorem///////////
        /////////is perfect square == 1////////
        if(is_perfect(n))   return 1;
        /////////n=a^2+b^2///////////
        for(int i=1 ; i<=sqrt(n/2);i++)
        {
            if(is_perfect(n - i*i)) return 2;
        }
        /////////////legends 4 square theorem ie. n = a^2 + b^2 + c^2 +d^2
        while(n%4 == 0) n/=4;
        if(n%8 == 7)    return 4;

    //////////////////////////else return 3///////////////////
        return 3;

    }
};