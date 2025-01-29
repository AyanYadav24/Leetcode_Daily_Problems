class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> f1(26,0),f2(26,0);
        for(char ch : p)
            f2[ch-'a']++;
        for(int i=0;i<s.length();i++){
            f1[s[i]-'a']++;
            if(i >= p.size()) f1[s[i-p.size()] - 'a']--;
            if(f1 == f2) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};