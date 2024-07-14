class Solution {
public:
    vector<vector<char>> b;
    string w;
    bool check(int i, int j, int itr, uint64_t table=0) {
        if (itr == w.size()) return true;
        if (i >= b.size() || i < 0) return false;
        if (j >= b[0].size() || j < 0) return false;
        int p=b[0].size()*i + j;
        ///////hashmap using uint64_t/////////
        uint64_t o=1,love;
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
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        b = board;
        w = word;
        int a=board.size(),b=board[0].size(),c=a*b;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (word[0] == board[i][j]) {
                    if (check(i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};