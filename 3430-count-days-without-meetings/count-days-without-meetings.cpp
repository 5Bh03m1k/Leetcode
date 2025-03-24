class Solution {
public:
    int countDays(int d, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        vector<int> st;
        st.push_back(m[0][0]);
        st.push_back(m[0][1]);
        for(int i=1;i<m.size();i++)
        {
            if(m[i][0]<=st.back())
            {
                if(m[i][1]>st.back())
                {
                    st.pop_back();
                    st.push_back(m[i][1]);
                }
            }
            else
            {
                st.push_back(m[i][0]);
                st.push_back(m[i][1]);
            }

        }

        int t=0;
        while(st.size()>0)
        {
            t+=st.back()+1;
            st.pop_back();
            t-=st.back();
            st.pop_back();
        }
        return d-t;
        
    }
};