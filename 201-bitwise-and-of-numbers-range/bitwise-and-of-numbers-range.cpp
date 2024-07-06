class Solution {
public:
    int rangeBitwiseAnd(int a, int b) {
        int res=1,flag=0,ans=0;
        // if(a==0 || b==0) return 0;
        // if(a==b) return a;
        while(true)
        {
            if(a==0 || b==0)
                break;
            if(a==b)
            {
                ans+=(res)*(a%2);
            }
            a=a>>1;
            b=b>>1;
            res=res<<1;
        }
            return ans;
    }
};