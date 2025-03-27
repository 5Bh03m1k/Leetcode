class Solution {
    int mod =1337;
public:
    int power(int a, int b )
    {
        int ans=1;
        while(b>0)
        {
            if(b%2 == 1)    ans*=a,ans%=mod;
            b=b>>1;
            a=((a%mod)*(a%mod))%mod;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int n=a,ans=1;
       for(int i=0 ; i<b.size() ; i++)
       {
            ans *=  power(n,b[b.size()-1-i]),ans %= mod;
            n=power(n,10);
            n%=mod;
       }
       return ans;
    }
};