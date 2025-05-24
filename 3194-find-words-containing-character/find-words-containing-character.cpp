class Solution {
public:
    bool ctn(string s, char ch)
    {
        for(int i= 0 ; i<s.size() ; i++)
        {
            if(s[i] == ch)   return true;
        }

        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i=0 ; i<words.size() ; i++)
        {
            if(ctn(words[i],x))
                ans.push_back(i);
        }

        return ans;
    }
};