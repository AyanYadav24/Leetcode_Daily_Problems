class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfs(int row, int col, vector<vector<int>>& grid, int m, int n) {
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) return 0;

        int curr_ans = grid[row][col];
        grid[row][col] = 0;

        for (auto& d : dir) {
            int new_row = row + d[0];
            int new_col = col + d[1];

            curr_ans += dfs(new_row,new_col,grid, m, n);
        }
        return curr_ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    ans = max(ans, dfs(i, j, grid, m, n));
            }
        }
        return ans;
    }
};