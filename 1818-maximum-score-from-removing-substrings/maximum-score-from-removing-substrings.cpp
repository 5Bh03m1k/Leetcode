class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x < y)   
        {
            reverse(s.begin() , s.end());
            swap(x,y);
        }

        int ans = 0;

        vector<char> st ,sn;

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == 'b' && st.size() > 0 && st.back() == 'a')
            {
                ans += x;
                st.pop_back();

                continue;
            }

            st.push_back(s[i]);
        }

        while(!st.empty())
        {
             if(st.back() == 'b' && sn.size() > 0 && sn.back() == 'a')
            {
                ans += y;
                sn.pop_back();

                goto tag;
            }

            sn.push_back(st.back());
            tag: st.pop_back();
        }
        return ans;
    }
};