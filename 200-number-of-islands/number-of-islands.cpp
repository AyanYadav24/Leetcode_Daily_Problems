class Solution {
private:
    vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int r, int c, vector<vector<char>>& mat){
        if(r<0 || c<0 || r>=mat.size() || c>=mat[r].size() || mat[r][c]=='0') return;
        mat[r][c] = '0';
       for(auto& dir : directions){
            int nr = r + dir[0];
            int nc = c + dir[1];
            dfs(nr,nc,mat);
       }
    }
public:
    int numIslands(vector<vector<char>>& mat) {
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == '1'){
                    cnt++;
                    dfs(i,j,mat);
                }
            }
        }
    return cnt;
    }
};