class Solution {
private:
    void dfs(int node, vector<vector<int>>& mat, vector<int>& vis){
        vis[node] = 1;
        for(int i=0;i<mat.size();i++){
            if(mat[node][i] && !vis[i])
                dfs(i,mat,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        vector<int> vis(mat.size(),0);
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            if(!vis[i]){
                dfs(i,mat,vis);
                cnt++;
            }
        }
    return cnt;
    }
};