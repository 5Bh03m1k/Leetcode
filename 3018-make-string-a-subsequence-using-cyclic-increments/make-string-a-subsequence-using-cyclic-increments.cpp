class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        queue<char> q;
        char ch;

        for(int i=0 ; i<str2.size() ; i++)
            q.push(str2[i]);
    
        for(int i=0 ; i<str1.size() ; i++)
        {
            if(q.size() > 0)
            {
                if(str1[i] == q.front() || (char)((int)str1[i] + 1) == q.front() || (str1[i] == 'z' && q.front() == 'a'))
                    q.pop();
            }
        }

        if(q.size() == 0)   return true;

        return false;
    }
};