class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,vector<int>> mp;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        for(auto it : mp){
            ans += (it.second.size() % 2 == 0) ? 2 : 1;
        }
        return ans;
    }
};