class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<int ,vector<int> , greater<int>> pc;
        priority_queue<int> pq;
        unordered_map<int , vector<int>> table;

        for(int i=0 ; i<p.size() ; i++)
        {
            if(table.count(c[i]) == 0)
                pc.push(c[i]);
            table[c[i]].push_back(p[i]);
        }

        for(int i=0 ; i<k  ; i++)
        {
            // if(p.size() <= i)  break;
            int tmp = 0;
            while(pc.top() <= w)
            {
                if(pc.size() == 0)  break;
                for(int i=0 ; i<table[pc.top()].size() ; i++)
                   pq.push(table[pc.top()][i]);
                pc.pop();
                
            }
            if(pq.size()==0)    break;
                w += pq.top();
            pq.pop();
        }

        return w;
    }
};