class Solution {
public:
    int minOperations(vector<string>& s) {
        int n = 0;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            switch( s[i][0] )
            {
                case '.':     switch( s[i][1] )
                                {
                                    case '.' : n = n > 0 ? n-1 : 0;
                                                break;
                                    default : break;
                                }
                                break;
                default :       n++;
                                break;
            }
        }
        return n;
    }
};