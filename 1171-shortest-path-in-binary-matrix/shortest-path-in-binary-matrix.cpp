class Solution {
public:
    vector<vector<int>> directions = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                                      {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[n-1][n-1] || grid[0][0])
            return -1;
        
        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto node = q.front();
            int dist = node.first;
            int x = node.second.first;
            int y = node.second.second;
            q.pop();

            if (x == n - 1 && y == n - 1)
                return dist;

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n && grid[x_][y_] == 0) {
                    q.push({dist+1, {x_, y_}});
                    grid[x_][y_] = 1;
                }
            }
        }
        return -1;
    }
};