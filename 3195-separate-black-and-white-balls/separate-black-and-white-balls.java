class Solution {
    public long minimumSteps(String s) {
        long count = s.length()-1,sum=0;
        for(int i=s.length()-1 ; i>=0 ; i--)
        {
            if(s.charAt(i) == '1')
            {
                sum+= count - i;
                count -- ;
            }
        }
        return sum;
    }
}