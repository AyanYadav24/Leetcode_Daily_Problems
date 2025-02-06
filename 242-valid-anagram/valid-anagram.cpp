class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if(n != m) return false;
        vector<int> cc(26,0);
        vector<int> ct(26,0);
        for(int i=0;i<n;i++){
            cc[s[i]-'a']++;
            ct[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(cc[i] != ct[i]) return false;
        }
        return true;
    }
};