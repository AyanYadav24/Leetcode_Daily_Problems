class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> mp(256,0);
        int l=0,r=0,len=0;
        while(r<n){
            while(mp[s[r]]){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            len = max(len,r-l+1);
            r++;
        }
    return len;
    }
};