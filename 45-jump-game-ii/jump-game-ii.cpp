class Solution {
public:
    vector<int> dp;
    int solve(int ind, vector<int>& nums, int n){
        if(ind == n - 1) return 0;
        if(dp[ind] != -1) return dp[ind];

        int cnt = 100000;
        for(int i = 1; i <= nums[ind]; i++) {
            if(ind + i < n)
                cnt = min(cnt,1 + solve(ind+i,nums,n));
        }
        return dp[ind] = cnt;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        dp.resize(n, -1);
        return solve(0, nums, n);
    }
};
