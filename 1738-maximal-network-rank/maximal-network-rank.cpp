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
        vector<int> r(n,0);
        vector<int>sr(n);
        vector<h_table> al(n);

        for(auto i:roads)
        {
            al[i[0]].insert(i[1]);
            al[i[1]].insert(i[0]);
            r[i[1]]++;
            r[i[0]]++;
        }

        int m = -1;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                m = max(m,al[i].find(j)? r[i] + r[j] -1 : r[i] +r[j]);
            }
        }

        return m;

        //return m;
    }
};