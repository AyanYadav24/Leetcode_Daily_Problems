class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,cnt=0,n=s.length();
        vector<int> mp(3,0);
        while(r<n){
            mp[s[r] - 'a']++;
            while(mp['a'- 'a']>0 && mp['b'- 'a']>0 && mp['c'- 'a']>0){
                cnt+=n-r;
                mp[s[l]-'a']--;
                l++;
            }
            r++;
        }
        
        return cnt;
    }
};