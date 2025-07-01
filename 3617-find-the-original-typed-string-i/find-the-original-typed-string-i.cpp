class Solution {
public:
    int possibleStringCount(string w) {
        int c = 1;

        for(int i = 1 ; i < w.size() ; i++)
           c += w[i] == w[i-1] ? 1 : 0;
        
        return c;
    }
};