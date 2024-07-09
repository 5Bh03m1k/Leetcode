class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        long long int wait = 0 , sec = 0;
        for( int i = 0 ; i < c.size() ; i++ )
        {
            if( c[i][0] < sec)
                sec += c[i][1];
            else
                sec =  c[i][1]  + c[i][0];
            wait += (sec - c[i][0]);
        }
        return wait/(double)c.size();
        
    }
};