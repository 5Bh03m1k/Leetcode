class Solution {
public:
    int mod = 1000000007;
    long long power(long long a , long long b ){
        long long ans = 1;
        while( b > 0){
            if( b%2 == 1)   ans = ( a *(long long) ans) % mod ;
            a  = ( a * a ) % mod;
            b /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
       // cout<<;
        return (int)( (long long)power( 4 , n/2 )%mod * (long long)power( 5 , (n/2+n%2) )%mod )%mod;
    }
};