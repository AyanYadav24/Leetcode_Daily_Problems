class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) return "";
        vector<int> mp(128, 0);

        for (char c : t) mp[c]++;

        int l = 0, r = 0, minLen = INT_MAX, start = 0;
        int count = n;

        while (r < m) {
            if(mp[s[r]] > 0)
                count--;
            mp[s[r]]--; //for all chars whether in map or not

            while(count == 0){
                int curr_len = r-l+1;
                if(minLen > curr_len){
                    minLen = curr_len;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0 ) count++;
                l++;
            }
            r++;
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
