class Solution {
public:
    vector<string> ans;
    string temp;

    void solve(int idx, string& s, unordered_set<string>& st) {
        if (idx >= s.length()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = idx; i < s.length(); i++) {
            string c = s.substr(idx, i - idx + 1);
            if (st.find(c) != st.end()) {
                if (idx != 0) temp += " " + c;
                else temp += c;
                solve(i + 1, s, st);
                if (idx != 0) temp.pop_back();
                for (int j = 0; j < c.length(); j++) temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        solve(0, s, st);
        return ans;
    }
};
