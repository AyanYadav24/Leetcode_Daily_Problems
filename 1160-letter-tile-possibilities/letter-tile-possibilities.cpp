class Solution {
public:
    void solve(int ind, string& s, vector<string>& ans, string& temp) {
        if (ind < 0) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(s[ind]);
        solve(ind - 1, s, ans, temp);

        while (ind > 0 && s[ind] == s[ind - 1])
            ind--;

        temp.pop_back();
        solve(ind - 1, s, ans, temp);
    }
    void permute(int ind, string s, set<string>& uniquePermutes) {
        if (ind == s.size()) {
            uniquePermutes.insert(s);
            return;
        }
        for (int i = ind; i < s.length(); i++) {
            swap(s[i], s[ind]);
            permute(ind + 1, s, uniquePermutes);
            swap(s[i], s[ind]);
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<string> ans;
        set<string> uniquePermutes;
        string temp = "";
        sort(tiles.begin(),tiles.end());
        solve(n-1,tiles,ans,temp);

        for (auto it : ans) {
            cout << it << endl;
        }

        for (auto it : ans) {
            permute(0, it, uniquePermutes);
        }
        return uniquePermutes.size() - 1;
    }
};