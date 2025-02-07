class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(int it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)) return true;
            }
            if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0), pathVis(n,0);

        for (int i = 0; i < n; i++) {
            dfs(i, graph, vis, pathVis);
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!pathVis[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

