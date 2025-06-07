class Solution {
public:
    string clearStars(string s) {
        priority_queue<char , vector<char> , greater<char> > pq;
        unordered_map<char , vector<int>> table;
        vector<bool> st(s.size(),false);

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] != '*')
            {
                pq.push(s[i]);
                table[s[i]].push_back(i);
            }
            
            else{
                st[table[pq.top()].back()] = true;
                table[pq.top()].pop_back();
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