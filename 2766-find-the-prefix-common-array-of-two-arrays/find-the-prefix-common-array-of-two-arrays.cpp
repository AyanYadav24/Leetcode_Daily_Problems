class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n,0);
        // vector<pair<bool,bool>> m(n+1,{false,false});
        map<int,pair<bool,bool>> m;
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            m[a[i]].first = true;
            m[b[i]].second = true;

            if(m[a[i]].second and m[b[i]].first and a[i] != b[i]) cnt+=2;
            else if(m[a[i]].second) cnt++;
            else if(m[b[i]].first) cnt++;

            ans[i] = cnt;
        }
    
        return ans;
    }
};