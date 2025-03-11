class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,cnt=0,n=s.length();
        unordered_map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                cnt+=n-r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        
        return cnt;
    }
};