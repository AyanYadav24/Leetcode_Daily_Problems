class Solution {
public:
    int solve(vector<int>& squares, int target, int ind, vector<vector<int>>& dp) {
        if (target == 0) return 0;
        if (ind < 0) return INT_MAX / 2;
        if (dp[target][ind] != -1) return dp[target][ind];
        
        int take = INT_MAX / 2;
        if (squares[ind] <= target) {
            take = 1 + solve(squares, target - squares[ind], ind, dp);
        }
        
        int not_take = solve(squares, target, ind - 1, dp);
        
        return dp[target][ind] = min(take, not_take);
    }

    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(squares.size(), -1));
        
        return solve(squares, n, squares.size() - 1, dp);
    }
};
