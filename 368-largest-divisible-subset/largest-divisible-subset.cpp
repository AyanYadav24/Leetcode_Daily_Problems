class Solution {
public:
    int n;
    void solve(int ind, vector<int>& nums, vector<int>& ans, vector<int>& temp, int last, vector<int>& dp){
        if(ind >= n){
            if(temp.size() > ans.size()) ans = temp;
            return;
        }

        if(nums[ind] % last == 0 && dp[ind] < (int)temp.size()+1){
            dp[ind] = temp.size() + 1;
            temp.push_back(nums[ind]);
            solve(ind+1,nums,ans,temp,nums[ind],dp);
            temp.pop_back();
        }

        solve(ind+1,nums,ans,temp,last,dp);


    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        vector<int> temp;
        vector<int> dp(nums.size(),-1);
        solve(0,nums,ans,temp,1,dp);
        return ans;
    }
};