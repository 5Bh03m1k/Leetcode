class Solution {
private:
    // Convert 2D board to 1D list in snaking order
    void make_list(vector<vector<int>>& board, vector<int>& list) {
        int n = board.size();
        bool leftToRight = true;

        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++)
                    list.push_back(board[i][j] == -1 ? -1 : board[i][j] - 1);
            } else {
                for (int j = n - 1; j >= 0; j--)
                    list.push_back(board[i][j] == -1 ? -1 : board[i][j] - 1);
            }
            leftToRight = !leftToRight;
        }
    }

    int bfs(vector<int>& a) {
        int n = a.size();
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            moves++;

            for (int k = 0; k < size; k++) {
                int curr = q.front(); q.pop();

                for (int i = 1; i <= 6; i++) {
                    int next = curr + i;
                    if (next >= n) continue;

                    if (a[next] != -1)
                        next = a[next];

                    if (next == n - 1) return moves;

                    if (!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> flatBoard;
        make_list(board, flatBoard);
        return bfs(flatBoard);
    }
};
