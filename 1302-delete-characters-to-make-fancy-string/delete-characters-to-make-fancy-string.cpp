class Solution {
public:
    string makeFancyString(string s) {
        deque<char> dq;
        unordered_map<char ,int> table;
        string sh = "";

        if(s.size() < 3) return s;

        for(int i = 0 ; i < 3 ; i++)
        {
            dq.push_back(s[i]);
            table[s[i]]++;
        }

        for(int i = 3 ; i < s.size() ; i++)
        {
            if(table[dq.front()] < 3)
                sh += dq.front();

            dq.push_back(s[i]);
            table[s[i]]++;

            table[dq.front()]--;
            dq.pop_front(); 
        }

        while(!dq.empty())
        {
            if(table[dq.front()] < 3)
                sh += dq.front();
            table[dq.front()]--;
            dq.pop_front();
        }

        return sh;
    }
};