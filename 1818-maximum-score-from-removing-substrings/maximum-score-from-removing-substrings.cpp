class Solution {
private:
    string chk(string s , int n ,int &ans)
    {
        vector<char> st;

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == 'b' && st.size() > 0 && st.back() == 'a')
            {
                ans += n;
                st.pop_back();

                continue;
            }

            st.push_back(s[i]);
        }

        string sh = "";
        while(!st.empty())
        {
            sh += st.back();
            st.pop_back();
        }

        return sh;
    }
public:
    int maximumGain(string s, int x, int y) {
        if(x < y)   
        {
            reverse(s.begin() , s.end());
            swap(x,y);
        }


        int a = 0;

        string s_n;
         
        s_n = chk(s,x,a);
        s_n = chk(s_n,y,a);

        return a;
    }
};