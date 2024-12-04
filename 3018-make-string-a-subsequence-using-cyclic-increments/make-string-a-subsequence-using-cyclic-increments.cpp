class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j=0;
        char ch;
    
        for(int i=0 ; i<str1.size() ; i++)
        {
            if(str2.size() > j)
            {
                if( str1[i] == str2[j] || (char)((int)str1[i] + 1) == str2[j] || (str1[i] == 'z' && str2[j] == 'a') )
                    j++;
            }
        }

        if(str2.size() == j)   return true;

        return false;
    }
};