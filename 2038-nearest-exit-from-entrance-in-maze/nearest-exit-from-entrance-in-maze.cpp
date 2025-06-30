class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';  // mark as visited

        int steps = 0;
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};  // 4 directions

        while (!q.empty()) {
            int n = q.size();
            steps++;

            for (int i = 0; i < n; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;

                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == '.') {
                        if (nx == 0 || ny == 0 || nx == rows - 1 || ny == cols - 1) {
                                return steps;
                        }
                        maze[nx][ny] = '+';  // mark visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};
