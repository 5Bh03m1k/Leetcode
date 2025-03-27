class Solution {
public:
    bool judgeSquareSum(int c) {
     long int  a=(int)sqrt(c),b=0;
      if(c%4 == 3)  return false;
      
     while( a > b )
     {
        if( a * a + b * b == c) 
            break;

        
        else if( a * a + b * b < c)
            b++;
        else if( a * a + b * b > c)
            a--;
     }

     if( a * a + b * b == c) 
        return true;
     return false;
        
    }
};