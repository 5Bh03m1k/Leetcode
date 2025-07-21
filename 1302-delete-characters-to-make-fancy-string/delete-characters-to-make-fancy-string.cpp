class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3)    return s;
        string sh = "";
        for(int i = 0 ; i < s.size()-2 ; i++)
        {
            if(s[i] != s[i+1] || s[i+2] != s[i])    sh+=s[i];
        }

        sh += s[s.size()-2];
        sh += s[s.size()-1];

        return sh;
    }
};