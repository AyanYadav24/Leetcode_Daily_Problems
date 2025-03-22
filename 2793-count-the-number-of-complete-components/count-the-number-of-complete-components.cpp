class Solution {
public:
    void dfs(int i, vector<int>& vis, unordered_map<int,vector<int>>& adj, int& vertices, int& edges){
        vis[i] = 1;
        vertices++;
        edges += adj[i].size();
        for(int t : adj[i]){
            if(!vis[t]){
                dfs(t,vis,adj,vertices,edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto& it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int vertices = 0, edges = 0;
                dfs(i,vis,adj,vertices,edges);
                if((vertices * (vertices - 1)) / 2 == edges / 2){
                    ans++;
                }
            }
        }
    return ans;
    }
};