class Solution {
public:
    vector<int> dp;
    bool solve(int ind, vector<int>& nums, int n){
        if(ind == n - 1) return true;
        if(dp[ind] != -1) return dp[ind];

        for(int i = 1; i <= nums[ind]; i++) {
            if(ind + i < n && solve(ind + i, nums, n))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        dp.resize(n, -1);
        return solve(0, nums, n);
    }
};
