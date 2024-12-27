class Solution {
public:
    bool isPossible(int vertex, int c, vector<vector<int>>& adj, vector<int>& color){
        for(int neighbour : adj[vertex]){
            if(color[neighbour] == c) return false;
        }
        return true;
    }
    bool solve(int vertex,vector<vector<int>>& adj, vector<int>& color, int n){
        if(vertex == n) return true;

        for(int i=1;i<=4;i++){
            if(isPossible(vertex,i,adj,color)) {
                color[vertex] = i;
                if(solve(vertex+1,adj,color,n)) return true;
                color[vertex] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color(n,0);
        vector<vector<int>> adj(n);

        for (int i = 0; i < paths.size(); i++) {
            adj[paths[i][0] - 1].push_back(paths[i][1] - 1);
            adj[paths[i][1] - 1].push_back(paths[i][0] - 1);

        }
        solve(0,adj,color,n);
        return color;
    }
};








// class Solution {
// public:
//     bool checkAvilableColor(int ver , vector<int>&color , vector<vector<int>> &mat , int k){
//         for(int i = 0 ; i < mat[ver].size() ; i++){
//             if( color[mat[ver][i]] == k)return false;
//         }
//         return true;
//     }
//     bool solve(int gar , vector<int>&color , vector<vector<int>> &mat){
//         if(gar == mat.size()) return true;

//         for(int k = 1 ; k <= 4 ; k++){
//             if(checkAvilableColor(gar , color , mat , k)){
//                 color[gar] = k;
//                 if(solve(gar+1 , color , mat)) return true;
//                 color[gar] = 0;
//             }
//         }
//         return false;
//     }
//     vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
//         vector<vector<int>> mat(n);
//         for(auto itr : paths){
//            mat[itr[0]-1].push_back(itr[1]-1);
//            mat[itr[1]-1].push_back(itr[0]-1);
//         }

//         vector<int> color(n , 0);
//         solve(0 , color , mat);
        
//         return color;
//     }
// };