#include <bitset>

class h_table {
private:
    std::bitset<100> a; // Use appropriate size

public:
    void insert(int n) {
        a.set(n);
    }

    void erase(int n) {
        a.reset(n);
    }

    bool find(int n) {
        return a.test(n);
    }
};


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> r(n,{0,0});
        vector<int>sr(n);
        vector<h_table> al(n);

        for(int i = 0 ; i < roads.size() ; i++)
        {
            al[roads[i][0]].insert(roads[i][1]);
            al[roads[i][1]].insert(roads[i][0]);
            r[roads[i][1]].first++;
            r[roads[i][1]].second = roads[i][1];
            r[roads[i][0]].first++;
            r[roads[i][0]].second = roads[i][0];
        }

        int m = -1;

        sort(r.begin(),r.end(),greater<pair<int,int>>());
        int kkk = r[0].first;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(r[i].first != kkk)   return m;
                int tmp =r[i].first + r[j].first ;
                
                tmp = al[r[i].second].find(r[j].second) ? tmp-1:tmp;
                
                if(m > tmp) break;
                m = tmp;
            }
        }

        return m;
    }
};