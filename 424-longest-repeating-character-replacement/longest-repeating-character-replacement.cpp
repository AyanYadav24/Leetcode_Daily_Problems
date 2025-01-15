class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int ans = 0;
        int n = s.length();
        int l = 0, r = 0, maxi = 0;
        while (r < n) {
            mp[s[r]]++;
            maxi = max(maxi, mp[s[r]]);
            int window = r - l + 1;
            if (window - maxi > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
