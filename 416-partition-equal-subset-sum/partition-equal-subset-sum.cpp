class Solution {
public:
    bool solve(int ind, vector<int>& nums, int tar, vector<vector<int>>& dp){
        if(tar == 0) return true;
        if(ind < 0 ) return false;

        if(dp[ind][tar] != -1) return dp[ind][tar];
        bool take = false;
        if(tar >= nums[ind]){
            take= solve(ind-1,nums,tar-nums[ind],dp);
        }
        bool not_take = solve(ind-1,nums,tar,dp);

        return dp[ind][tar] =  take || not_take;

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int num : nums) sum += num;
        if(sum%2) return false;
        int tar = sum / 2;
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        return solve(n-1,nums,sum/2,dp);
    }
};