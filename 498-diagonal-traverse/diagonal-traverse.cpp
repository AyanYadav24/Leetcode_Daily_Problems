class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool rev = false;
        for(auto& it : mp){
            rev = !rev;
            if(rev) reverse(it.second.begin(),it.second.end());
            for(int num : it.second) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};