class Solution {
public:
    string makeFancyString(string s) {
        int table[26]={0};
        int tmp = 0;
        string sh = "";

        if(s.size() < 3) return s;

        for(int i = 0 ; i < 3 ; i++)
            table[s[i] -'a']++;
        

        for(int i = 3 ; i < s.size() ; i++)
        {
            tmp = i-3;
            if(table[s[tmp]-'a'] < 3)
                sh += s[tmp];
            table[s[i]-'a']++;
            table[s[tmp]-'a']--;
        }
        tmp = s.size() - 3;
        while(tmp < s.size())
        {
            if(table[s[tmp]-'a'] < 3)
                sh += s[tmp];
            table[s[tmp]-'a']--;
            tmp ++;
        }

        return sh;
    }
};