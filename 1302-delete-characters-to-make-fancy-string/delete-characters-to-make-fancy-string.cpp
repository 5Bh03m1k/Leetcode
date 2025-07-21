class Solution {
public:
    string makeFancyString(string s) {
        unordered_map<char ,int> table;
        int tmp = 0;
        string sh = "";

        if(s.size() < 3) return s;

        for(int i = 0 ; i < 3 ; i++)
            table[s[i]]++;
        

        for(int i = 3 ; i < s.size() ; i++)
        {
            tmp = i-3;
            if(table[s[tmp]] < 3)
                sh += s[tmp];
            table[s[i]]++;
            table[s[tmp]]--;
        }
        tmp = s.size() - 3;
        while(tmp < s.size())
        {
            if(table[s[tmp]] < 3)
                sh += s[tmp];
            table[s[tmp]]--;
            tmp ++;
        }

        return sh;
    }
};