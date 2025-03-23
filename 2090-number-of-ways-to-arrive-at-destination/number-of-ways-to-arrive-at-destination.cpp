class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
         for (int j = 0; j < roads.size(); j++) {
            int u = roads[j][0], v = roads[j][1], w = roads[j][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

        vector<long long>dist(n,LLONG_MAX);
        int mod=(1e9+7);
        vector<int>path(n,0);
        path[0]=1;
        dist[0]=0;
        q.push({0,0});
        while(!q.empty()){
            int node=q.top().second;
            long long d=q.top().first;
            q.pop();

            for(int i=0;i<adj[node].size();i++){
                int neighbour=adj[node][i].first;
                int weight=adj[node][i].second;
                if(dist[neighbour]>d+weight){
                    dist[neighbour]=d+weight;
                    q.push({dist[neighbour],neighbour});
                    path[neighbour]=path[node];

                }
                else if(dist[neighbour]==d+weight){
                    path[neighbour]=(path[neighbour]+path[node])%mod;
                }
            }
        }
        return path[n-1]%mod;

        
    }
};