class Solution {
public:
    int dp[201][1001];
    int solve(int idx, int tar, vector<int>& nums){
        if(idx >= nums.size()){
            if(tar == 0) return 1;
            return 0;
        }
        
        if(dp[idx][tar] != -1) return dp[idx][tar];

        int take = 0;
        if(nums[idx] <= tar)
            take = solve(0,tar-nums[idx],nums);
        int not_take = solve(idx+1,tar,nums);

        return dp[idx][tar] = take + not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,target,nums);
    }
};