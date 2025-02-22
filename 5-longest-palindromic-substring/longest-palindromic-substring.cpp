class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    string longestPalindrome(string s) {
        int n = s.length();
        int p=0,q=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if( j-i+1 > ans && isPalindrome(i,j,s)){
                    ans = j-i+1;
                    p=i;q=j;
                }
            }
        }
    return s.substr(p,q-p+1);
    }
};