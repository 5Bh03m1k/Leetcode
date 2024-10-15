class Solution {
public:
    long long minimumSteps(string s) {
        long long count = s.size()-1,sum=0;
        for(int i=s.size()-1 ; i>=0 ; i--)
        {
            if(s[i] == '1')
            {
                sum+= count - i;
                count -- ;
            }
        }
        return sum;
    }
};