class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto nodes : prerequisites){
            int u = nodes[0];
            int v = nodes[1];
            adj[v].push_back(u);
        }
        vector<int> order;
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return order.size()==n ? true : false;
    }
};