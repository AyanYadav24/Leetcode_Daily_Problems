class Solution {
public:
    int n,m;

    int solve(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp){
        if(i >= n || j >= m) return 0;

        if(matrix[i][j] == '0') return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i,j+1,matrix,dp);
        int down = solve(i+1,j,matrix,dp);
        int diag = solve(i+1,j+1,matrix,dp);

        return dp[i][j] = 1 + min({right, down, diag});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    ans = max(ans,solve(i,j,matrix,dp));
                }
            }
        }
    return ans*ans;
    }
};