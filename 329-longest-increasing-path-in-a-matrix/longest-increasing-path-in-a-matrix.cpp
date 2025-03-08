class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
    int solve(int i, int j, vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& dp){

        if(dp[i][j] != -1) return dp[i][j];
        int path_cnt = 1;
        for(auto dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

             if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && matrix[i_][j_] > matrix[i][j]){
                if(matrix[i_][j_] > matrix[i][j])
                    path_cnt = max(path_cnt,1+solve(i_,j_,matrix,m,n,dp));
            }
        }
        return dp[i][j] = path_cnt;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,solve(i,j,matrix,m,n,dp));
            }
        }
    return ans;
    }
};