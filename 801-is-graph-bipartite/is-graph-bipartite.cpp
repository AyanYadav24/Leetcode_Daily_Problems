class Solution {
public:
    bool dfs(int node, int cc, vector<vector<int>>& graph, vector<int>& color){
        color[node] = cc;
        for(auto& itr : graph[node]){
            if(color[itr] == cc) return false;
            if(color[itr] == -1){
                if(dfs(itr,!cc,graph,color) == false) return false; 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i,1,graph,color)==false) return false;
            }
        }
        return true;
    }
};