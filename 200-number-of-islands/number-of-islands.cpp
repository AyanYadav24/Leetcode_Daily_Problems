class Solution {
private:
    vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int r, int c, vector<vector<char>>& mat, vector<vector<int>>& vis){
        if(r<0 || c <0 || r>=mat.size() || c>=mat[r].size() || mat[r][c]=='0' || vis[r][c] == 1) return;
        vis[r][c] = 1;
       for(auto& dir : directions){
        int nr = r + dir[0];
        int nc = c + dir[1];
        dfs(nr,nc,mat,vis);
       }
    }
public:
    int numIslands(vector<vector<char>>& mat) {
        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(!vis[i][j] && mat[i][j] == '1'){
                    cnt++;
                    dfs(i,j,mat,vis);
                }
            }
        }
    return cnt;
    }
};