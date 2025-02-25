class Solution {
public:
    int t[1001][1001];
    bool isPalindrome(int i, int j, string& s) {
    if(i>=j) return t[i][j] = 1;
    if(t[i][j] != -1) return t[i][j];
    if(s[i] == s[j]) return t[i][j] = isPalindrome(i+1,j-1,s);
    return t[i][j] = 0;
}
    string longestPalindrome(string s) {
        int n = s.length();
        int p=0;
        int ans = 0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            if(n-i <= ans) continue;
            for(int j=i;j<n;j++){
                if( j-i+1 > ans && isPalindrome(i,j,s)){
                    ans = j-i+1;
                    p=i;
                }
            }
        }
    return s.substr(p,ans);
    }
};