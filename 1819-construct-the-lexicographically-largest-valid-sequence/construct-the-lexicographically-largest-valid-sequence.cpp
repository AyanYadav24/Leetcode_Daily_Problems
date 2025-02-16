class Solution {
public:
    bool solve(int ind, int n, vector<int>& ans, vector<int>& used) {

        if (ind >= ans.size())
            return true;

        if (ans[ind] != -1) return solve(ind + 1, n, ans, used);

        for (int i = n; i >= 1; i--) {
            if (used[i])
                continue;

            if (i == 1) {
                ans[ind] = i;
                used[i] = 1;
                if (solve(ind + 1, n, ans, used)) return true;
                used[i] = 0;
                ans[ind] = -1;
            }
            else{
                if(ind + i < ans.size() && ans[ind + i] == -1) {
                    used[i] = 1;
                    ans[ind] = i;
                    ans[ind + i] = i;
                    if (solve(ind + 1, n, ans, used)) return true;
                    used[i] = 0;
                    ans[ind] = -1;
                    ans[ind + i] = -1;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);
        vector<int> used(n + 1, 0);
        solve(0, n, ans, used);
        return ans;
    }
};