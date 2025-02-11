class Solution {
public:
    string removeOccurrences(string s, string p) {
        int n = s.size();
        int m = p.size();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == p[m-1] && ans.size() >= m-1){
                if(ans.substr(ans.size()-m+1,m-1) == p.substr(0,m-1)){
                    ans.erase(ans.size() - m + 1);
                }
                else
                    ans.push_back(s[i]);
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};