class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= m; i2++) {
                if (s1[i1 - 1] == s2[i2 - 1])
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                else
                    dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
            }
        }
        //recovering the shorteest string to cover both the strings as subsequence
        string s = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                s += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                s += s1[i - 1];
                i--;
            } else {
                s += s2[j - 1];
                j--;
            }
        }
        while(i > 0){
            s+=s1[i-1];
            i--;
        }
        while(j > 0){
            s+=s2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
    return s;
    }
};