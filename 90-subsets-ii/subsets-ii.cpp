class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp){
        if(ind < 0){
            ans.push_back(temp);
            return;
        } 
        temp.push_back(nums[ind]);
        solve(ind - 1,nums,ans,temp);

        while(ind >  0 && nums[ind] == nums[ind-1]) ind--;

        temp.pop_back();
        solve(ind - 1,nums,ans,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<int> temp;
        solve(n-1,nums,ans,temp);
        return ans;
    }
};