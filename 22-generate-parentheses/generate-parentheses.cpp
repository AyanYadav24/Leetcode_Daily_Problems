class Solution {
public:
    void solve(int o,int c, int n, vector<string>& ans, string s){
        if(s.length() == 2*n) {
            ans.push_back(s);
            return;
        }
        if(o<n){
            s+='(';
            solve(o+1,c,n,ans,s);
            s.pop_back();
        }
        if(c<n && c<o){
            s+=')';
            solve(o,c+1,n,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        int open=0,close=0;
        solve(open,close,n,ans,s);
    return ans;
    }
};