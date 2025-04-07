class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i=0;i<n;i++) s+=nums[i];

        if(s%2 != 0) return false;

        int k = s/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));

        for(int i=0;i<n;i++) dp[i][0] = true;
        if(nums[0]<=k) dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=k;t++){
                int not_take = dp[i-1][t];
                int take = false;
                if(t >= nums[i]) take = dp[i-1][t-nums[i]];
                dp[i][t] = take || not_take;
            }
        }
        return dp[n-1][k];
    }
};