class Solution {
public:
    string convertToBase7(int n) {
        string s="";
        bool flag=false;
        int ans;

        if(n == 0)  return to_string(0);
        if(n<0) n=-n,flag=true;

        while(n>0){
            ans = n%7;
            s=to_string(ans)+s;
            n/=7;
        }
        if(flag){
            string m = "-";
            s = m + s;
        }

        return s;
    }
};