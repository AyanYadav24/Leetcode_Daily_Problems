class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      set<string> set(wordDict.begin(),wordDict.end());
      
      int n=s.size();
      vector<bool> v(n+1, false);
      v[0]=true;
        for(int i=1;i<=n;i++) {
          for(string w : wordDict) {
            int start=i-w.size();
            if(start>=0 && v[start] && s.substr(start,w.size())==w) {
              v[i]=true;
              break;
            }
          }
        }
        return v[n];
        
    }
};