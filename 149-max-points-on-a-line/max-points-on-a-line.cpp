class Solution {
public:
    int area(int x1,int x2, int x3 , int y1, int y2 , int y3)
    {
        int a = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
        return a;
    }
    int maxPoints(vector<vector<int>>& s) {
        int max = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            for(int j = i+1 ; j<s.size() ; j++)
            {
                int total = 0;
                for(int k=j+1 ; k<s.size() ; k++)
                {
                    if(k != i || k!= j)
                    {
                        if(area(s[i][0],(s[j][0]),(s[k][0]),(s[i][1]),(s[j][1]),(s[k][1])) == 0)
                            total++;
                    }
                }
                max = total>max ? total : max;
            }
            
        }
    return max+(s.size()>2?2:s.size());
    }
};