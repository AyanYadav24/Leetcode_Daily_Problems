class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis){
        vis[node] = 1;
        for(auto it : adjList[node]){
            if(!vis[it])
                dfs(it,adjList,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        vector<vector<int>> adjList(mat.size());
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for(auto i : adjList){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        vector<int> vis(adjList.size(),0);
        int cnt = 0;
        for(int i=0;i<adjList.size();i++){
            if(!vis[i]){
                dfs(i,adjList,vis);
                cnt++;
            }
        }
    return cnt;
    }
};