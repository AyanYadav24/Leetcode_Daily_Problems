class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        int m = mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        vector<int>rows(m,0);
        vector<int>cols(n,0);
        for(int i=0;i<arr.size();i++){
            int num = arr[i];
            int row = mp[num].first;
            int col = mp[num].second;

            rows[row]++;cols[col]++;

            if(rows[row] == n || cols[col] == m) return i;
        }
        return -1;
    }
};