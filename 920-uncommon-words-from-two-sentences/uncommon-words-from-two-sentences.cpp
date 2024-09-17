class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> table;
        string s="";
        for(int i=0 ; i<s1.size() ; i++)
        {
            if(s1[i]    ==  ' ')
                {
                    if(table.find(s)!= table.end())
                        table[s]=INT_MAX;
                    else
                        table[s]=0;
                    s="";
                }
            else
            s+=s1[i];
        }
        if(table.find(s)!= table.end())
                    table[s]=INT_MAX;
        else
            table[s]=0;
        s="";
        for(int i=0 ; i<s2.size() ; i++)
        {
            if(s2[i]    ==  ' ')
               {
                    if(table.find(s)!= table.end())
                        table[s]=INT_MAX;
                    else
                        table[s]=0;
                    s="";
               }
            else
            s+=s2[i];
        }
        if(table.find(s)!= table.end())
            table[s]=INT_MAX;
        else
            table[s]=0;
        s="";
        vector<string> res;
        for(auto it = table.begin() ; it!=table.end() ; it++)
        {
            if(it->second == 0)
                res.push_back(it->first);

        }
        return res;
    }
};