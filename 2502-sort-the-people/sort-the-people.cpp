class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<pair<int, string>> comb;
        for (int i = 0; i < n; i++) {
            comb.emplace_back(heights[i], names[i]);
        }

        sort(begin(comb), end(comb), greater<>());

        vector<string> ans;

        for (const auto& [_, name] : comb)
            ans.push_back(name);
        return ans;
    }
};