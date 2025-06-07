class Solution {
public:
    string clearStars(string s) {
        priority_queue<char , vector<char> , greater<char> > pq;
        vector<vector<int>> table(26);
        vector<bool> st(s.size(),false);

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] != '*')
            {
                pq.push(s[i]);
                table[s[i] - 'a'].push_back(i);
            }
            
            else{
                st[table[pq.top() - 'a'].back()] = true;
                table[pq.top() - 'a'].pop_back();
                pq.pop();
            }
        }
        
        string ans = "";

        for(int i=0 ; i < s.size() ; i++)
        {
            if(st[i] || s[i] == '*')
                continue;
            
             ans.push_back(s[i]);
            
        }

        return ans;

    }
};