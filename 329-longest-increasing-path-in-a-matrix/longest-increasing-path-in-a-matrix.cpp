class Solution {
private:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int maxPath = 1;
        for(auto &d : dir){
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni>=0 && nj>=0 && ni< matrix.size() && nj<matrix[0].size() && matrix[ni][nj]>matrix[i][j]){
                maxPath = max(maxPath, 1 + dfs(ni,nj,matrix,dp));
            }
        }

        return dp[i][j]=maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans =0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int path = dfs(i,j,matrix,dp);
                ans = max(path,ans);
            }
        }

        return ans;
    }
};