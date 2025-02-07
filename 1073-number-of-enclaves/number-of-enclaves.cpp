class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( (i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]== 1 ){
                    grid[i][j] = 2;
                    q.push({i,j});
                }
            }
        }
        int rd[4] = {-1,0,0,1};
        int cd[4] = {0,1,-1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + rd[i];
                int nc = c + cd[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};