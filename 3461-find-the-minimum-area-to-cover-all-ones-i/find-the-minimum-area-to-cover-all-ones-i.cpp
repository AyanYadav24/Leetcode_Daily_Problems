class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int min_i = INT_MAX, min_j = INT_MAX;
        int max_i = INT_MIN, max_j = INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    min_i = min(i,min_i);
                    min_j = min(j,min_j);
                    max_i = max(i,max_i);
                    max_j = max(j,max_j);
                }
            }
        }
        int minimumArea = (max_i - min_i + 1) * (max_j - min_j + 1);
        return minimumArea;
    }
};