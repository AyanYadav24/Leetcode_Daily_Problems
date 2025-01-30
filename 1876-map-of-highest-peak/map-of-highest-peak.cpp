class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> heights(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               if(isWater[i][j] == 1){
                 q.push({i,j});
                 heights[i][j] = 0;
               }
            }
        }
        while(!q.empty()){
           pair<int,int> node = q.front();
           q.pop();
           int x = node.first;
           int y = node.second;
           for(auto& dir : directions){
            int nx = x + dir[0];
            int ny = y + dir[1];
            if(nx >=0 && nx < m && ny >= 0 && ny < n && heights[nx][ny] == -1){
                heights[nx][ny] = heights[x][y] + 1;
                q.push({nx,ny});
            }
           } 
        }
        return heights;
    }
};