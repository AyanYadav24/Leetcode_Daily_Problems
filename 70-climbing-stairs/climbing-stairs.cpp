class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n<0) return 0;
        if(n==0 || n==1) return 1;

        if(dp[n]) return dp[n];

        int one = solve(n-1);
        int two = solve(n-2);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};