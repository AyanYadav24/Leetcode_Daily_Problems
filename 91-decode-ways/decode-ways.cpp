class Solution {
public:
    bool validTwoDigit(string& s, int ind){
        int num = (s[ind] - '0')*10 + (s[ind+1] - '0');
        return num >= 10 && num <= 26;
    }
    int solve(int ind, string& s, vector<int>& dp){
        if(ind >= s.size()) return 1;
        if(dp[ind] != -1) return dp[ind];
        if(s[ind] == '0') return dp[ind]=0;
        int res = solve(ind+1,s,dp);
        if(ind < s.size()-1 && validTwoDigit(s,ind)){
            res += solve(ind+2,s,dp);
        }
        return dp[ind] = res;
    }
    int numDecodings(string s) {
       vector<int> dp(s.size(),-1);
       return solve(0,s,dp);
    }
};