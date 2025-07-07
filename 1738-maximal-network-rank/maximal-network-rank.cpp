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

        for(auto i:roads)
        {
            al[i[0]].insert(i[1]);
            al[i[1]].insert(i[0]);
            r[i[1]].first++;
            r[i[1]].second = i[1];
            r[i[0]].first++;
            r[i[0]].second = i[0];
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

        //return m;
    }
};