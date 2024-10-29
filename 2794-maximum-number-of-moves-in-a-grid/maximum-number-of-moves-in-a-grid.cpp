class Solution {
public:
    int n,m;
    int solve(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if( i>=n || j >=m || i<0 || j<0 ) return 0;

        if(grid[i][j] <= prev) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int diag_up = solve(i-1,j+1,grid[i][j],grid,dp);
        int right = solve(i,j+1,grid[i][j],grid,dp);
        int diag_down = solve(i+1,j+1,grid[i][j],grid,dp);

        return dp[i][j] = 1 + max({diag_up,right,diag_down});
    }
    int maxMoves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,solve(i,0,-1,grid,dp));
        }
    return ans-1;
    }
};