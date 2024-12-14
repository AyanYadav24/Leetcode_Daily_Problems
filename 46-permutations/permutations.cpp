class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int vis[]){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i] == 0){
                vis[i] = 1;
                temp.push_back(nums[i]);
                solve(nums,temp,ans,vis);
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int vis[6] = {0};
        solve(nums, temp, ans, vis);
        return ans;
    }
};