class Solution {
public:
    bool bfsCycle(vector<list<int>>& adj, vector<int>& parent, vector<int>& vis, int src) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int itr : adj[node]) {
                if (!vis[itr]) {
                    vis[itr] = 1;
                    parent[itr] = node;
                    q.push(itr);
                } else if (parent[node] != itr) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<list<int>> adj(n);
        vector<int> parent(n, -1);
        vector<int> vis(n, 0);
        vector<int> ans(2, 0);

        for (auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);

            fill(parent.begin(), parent.end(), -1);
            fill(vis.begin(), vis.end(), 0);

            if (bfsCycle(adj, parent, vis, u)) {
                ans = {edge[0], edge[1]};
                break;
            }
        }

        return ans;
    }
};
