class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.length();
        for(int i=0;i<n;i++){
            if(i>1 && s[i] == s[i-1] && s[i] == s[i-2]) continue;
            else ans+=s[i];
        }
    return ans;
    }
};