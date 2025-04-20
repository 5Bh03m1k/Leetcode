class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> p_table;

public:
    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        p_table[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;

        // Only check vertical alignment (same x)
        for (const auto& [col_x, y_map] : p_table) {
            if (col_x == x) continue; // Skip same column

            int d = col_x - x; // Distance between x's
            // Check two potential squares: (x, y ± d)
            for (int sign : {-1, 1}) {
                int y1 = y + d * sign;
                if (p_table[x].count(y1) && p_table[col_x].count(y1) && p_table[col_x].count(y)) {
                    res += p_table[x][y1] * p_table[col_x][y] * p_table[col_x][y1];
                }
            }
        }
        return res;
    }
};
