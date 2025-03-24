class Solution {
public:
    int countDays(int d, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        stack<int> st;
        st.push(m[0][0]);
        st.push(m[0][1]);
        for(int i=1;i<m.size();i++)
        {
            if(m[i][0]<=st.top())
            {
                if(m[i][1]>st.top())
                {
                    st.pop();
                    st.push(m[i][1]);
                }
            }
            else
            {
                st.push(m[i][0]);
                st.push(m[i][1]);
            }

        }

        int t=0;
        while(st.size()>0)
        {
            t+=st.top()+1;
            st.pop();
            t-=st.top();
            st.pop();
        }
        return d-t;
        
    }
};