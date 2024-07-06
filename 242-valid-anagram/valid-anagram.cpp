class Solution {
public:
    bool chk(string s, string t)
    {
        int a[26]={0},n=s.size();
        for(int i=0;i<n;i++)
            a[s[i]-'a']++,a[t[i]-'a']--;
        for(int i=0; i<26;i++)
        {
            if(a[i]!=0)
                return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        
          if( s.size()==t.size()) 
          return chk(s,t);
          return false;
        
    }
};