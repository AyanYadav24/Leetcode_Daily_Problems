class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n,0);
        vector<pair<bool,bool>> m(n+1,{false,false});
        
        for(int i=0;i<n;i++){
            m[a[i]].first = true;
            m[b[i]].second = true;

            int cnt = 0;
            for(int k=0;k<=n;k++){
                if(m[k].first and m[k].second) cnt++;
            }
            ans[i] = cnt;
        }
        //ans[n-1]++;

        return ans;
    }
};