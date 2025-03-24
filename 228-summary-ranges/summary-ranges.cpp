class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        stack<int> st;
        string s;
        vector<string> ans;

        for(int i=0 ; i<nums.size() ; i++)
        {
            if(st.size()==0)
                st.push(nums[i]);
            else if(st.top()+1 == nums[i])
            {
                if(st.size() == 2)
                    st.pop();
                st.push(nums[i]);
            }
            else{
                if(st.size() == 1) {
                     s=s+to_string(st.top());
                     st.pop();
                }
                else{
                    s = s+to_string(st.top());
                    st.pop();
                    s= "->"+s;
                    s=to_string(st.top())+s;
                    st.pop();
                }
                ans.push_back(s);
                cout<<s;
                s.clear();
                st.push(nums[i]);
            }
        }
        if(st.size() != 0)
        {
            if(st.size() == 1) {
                     s=s+to_string(st.top());
                     st.pop();
                }
                else{
                    s = s+to_string(st.top());
                    st.pop();
                    s= "->"+s;
                    s=to_string(st.top())+s;
                    st.pop();
                }
                ans.push_back(s);
                cout<<s;
                s.clear();
            
        }
        //ans.push_back(s);

        return ans;
    }
};