class Solution {
public:
    bool solve(int idx, string& s, set<string>& st, vector<int>& dp) {
        if (idx >= s.length()) return true;
        if (dp[idx] != -1) return dp[idx];

        for (int i = idx; i < s.length(); i++) {
            if (st.find(s.substr(idx, i - idx + 1)) != st.end()) {
                if (solve(i + 1, s, st, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return solve(0, s, st, dp);
    }
};
