class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        if (col < 0 || col == matrix[row].size()) return INT_MAX;

        if(dp[row][col] != INT_MAX) return dp[row][col];
    
        if (row == 0) return matrix[row][col];

        int upl = solve(row - 1, col - 1, matrix,dp);
        int upr = solve(row - 1, col + 1, matrix,dp);
        int top = solve(row - 1, col, matrix,dp);

        return dp[row][col] = matrix[row][col] + min(upl, min(upr, top));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, solve(n - 1, i, matrix,dp));
        }
        return mini; 
    }
};