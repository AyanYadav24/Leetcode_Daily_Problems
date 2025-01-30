class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& cnt) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col]) return;
        
        visited[row][col] = true;
        cnt++;
        
        for (auto& dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            dfs(new_row, new_col, grid, visited, cnt);
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_count(m, 0), col_count(n, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int totalServers = 0;

        // Count the number of servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        // DFS to count the servers that can communicate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int cnt = 0;
                    dfs(i, j, grid, visited, cnt);
                    if (cnt > 1 || row_count[i] > 1 || col_count[j] > 1) {
                        totalServers += cnt;
                    }
                }
            }
        }
        return totalServers;
    }
};
