class Solution {
public:
    string clearStars(string s) {
        priority_queue<char , vector<char> , greater<char> > pq;
        unordered_map<char , priority_queue<int>> table;
        priority_queue<int , vector<int> , greater<int>> st;

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] != '*')
            {
                pq.push(s[i]);
                table[s[i]].push(i);
            }
            
            else{
                st.push(table[pq.top()].top());
                table[pq.top()].pop();
                pq.pop();
            }
        }
        if(st.size()>0)cout<<st.top();
        string ans = "";

        for(int i=0 ; i < s.size() ; i++)
        {
            if(st.size() > 0 && st.top() == i)
            {
                st.pop();
                goto tag;
            }

            if(s[i] == '*')
                goto tag;
            
             ans.push_back(s[i]);

            tag:
        }

        return ans;

    }
};