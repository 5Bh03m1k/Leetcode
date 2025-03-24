class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> st,add;
        for(int i = 0 ; i < arr.size() ; i++ )
        {
            if(st.size()==0 || st.back()<arr[i][0])
            {
                st.push_back(arr[i][0]);
                st.push_back(arr[i][1]);
            }

            else{
                if(st.back()<arr[i][1])
                {
                    st.pop_back();
                    st.push_back(arr[i][1]);
                }
            }
        }

        arr.clear();

        for(int i=0 ; i<st.size() ; i+=2)
        {
            add.push_back(st[i]);
            add.push_back(st[i+1]);
            arr.push_back(add);
            add.clear();
        }
        return arr;
    }
};