class Solution {
public:
    vector<vector<char>> b;
    string w;
    bool check(int i, int j, int itr, long long unsigned int &table) {
        if (itr == w.size()) return true;
        if (i >= b.size() || i < 0) return false;
        if (j >= b[0].size() || j < 0) return false;
        int p=b[0].size()*i + j;
        long long unsigned int o=1,love;
        o=o<<p;
        love = table & o;
         if (love != 0) return false;
        if (b[i][j] != w[itr]) return false;
         love = table;
        table = table | o;
        bool res= check(i + 1, j, itr + 1,table) || check(i - 1, j, itr + 1,table) || check(i, j + 1, itr + 1,table) || check(i, j - 1, itr + 1,table);
        table = love;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        w = word;
        long long unsigned int t=0;
        int a=board.size(),b=board[0].size(),c=a*b;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (word[0] == board[i][j]) {
                    if (check(i, j, 0,t))
                        return true;
                }
            }
        }
        return false;
    }
};