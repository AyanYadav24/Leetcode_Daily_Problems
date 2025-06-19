class Solution {
public:
    char dfs(char c, unordered_map<char,vector<char>>& g,vector<int>& vis){
        vis[c-'a'] = 1;
        char mini = c;
        for(char d : g[c]){
            if(!vis[d-'a']){
                mini = min(mini,dfs(d,g,vis));
            }
        }
    return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //dfs
        unordered_map<char,vector<char>> g;
        for(int i=0;i<s1.length();i++){
                g[s1[i]].push_back(s2[i]);
                g[s2[i]].push_back(s1[i]);
        }
        string lexi;
        for(char c : baseStr){
            vector<int> vis(26,0);
            char minc = dfs(c,g,vis);
            lexi += minc;
        }
    return lexi;
    }
};