class Solution {
public:
    

    bool chk(unordered_map<int , unordered_set<int>>& a)
    {
        bool v = true , h = true;
        for(int i = 0 ; i < 3 ; i ++)
        {
            bool tmp = true,tmp1 = true;
            for(int j=0 ; j<3 ; j++)
            {
                tmp = (a[i].find(j) != a[i].end()) & tmp;
                tmp1 = (a[j].find(i) != a[j].end()) & tmp1;
            }
            if(tmp || tmp1) return true;
        }

        for(int i = 0 ; i < 3 ; i++)
        {
            v = v & (a[i].find(i) != a[i].end());
            h = h & (a[2-i].find(i) != a[2-1].end());
        }

        return v | h;
    }

    string tictactoe(vector<vector<int>>& m) {
        unordered_map<int , unordered_set<int>> a,b;        

        for(int i=0 ; i < m.size() ; i++)
        {
            if(i%2 == 0)    a[m[i][0]].insert(m[i][1]);
            else            b[m[i][0]].insert(m[i][1]);
        }

        if(chk(a))  return "A";
        if(chk(b))  return "B";
        if(m.size() < 9)    return "Pending";
        return "Draw";
        
    }
};