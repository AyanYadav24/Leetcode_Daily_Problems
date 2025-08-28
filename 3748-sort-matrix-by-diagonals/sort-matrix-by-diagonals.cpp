class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[j-i].push_back(grid[i][j]);
            }
        }
        for(auto& it : mp) {
            if(it.first > 0 ) sort(it.second.begin(),it.second.end());
            else sort(it.second.begin(),it.second.end(),greater<int>());
        }

        unordered_map<int, int> indices;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int diff = j - i;
                grid[i][j] = mp[diff][indices[diff]];
                indices[diff]++;
            }
        } 
        return grid;
    }
};