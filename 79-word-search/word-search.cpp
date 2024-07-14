class Solution {
public:
    vector<vector<char>> b;
    string w;
    bool check(int i, int j, int itr, uint64_t table) {
        if (itr == w.size()) return true;
        if (i >= b.size() || i < 0 || j >= b[0].size() || j < 0 ||b[i][j] != w[itr]) return false;
        b[i][j]='*';
        bool res =  check(i + 1, j, itr + 1,table) || check(i - 1, j, itr + 1,table) || check(i, j + 1, itr + 1,table) || check(i, j - 1, itr + 1,table);
        b[i][j]=w[itr];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        w = word;
        uint64_t table=0;
        int a=board.size(),b=board[0].size(),c=a*b;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (word[0] == board[i][j]) {
                    if (check(i, j,0,table))
                        return true;
                }
            }
        }
        return false;
    }
};