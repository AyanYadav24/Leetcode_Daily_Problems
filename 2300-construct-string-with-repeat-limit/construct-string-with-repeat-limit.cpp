class Solution { 
public:
    string repeatLimitedString(string s, int rl) {
        unordered_map<char, int> mp;
        priority_queue<pair<char, int>> pq;

        for (char ch : s) {
            mp[ch]++;
        }

        for (const auto& it : mp) {
            pq.push({it.first, it.second});
        }

        string ans = "";
        
        while (!pq.empty()) {
            auto [ch, occ] = pq.top();
            pq.pop();
            
            if (occ > rl) {
                ans += string(rl, ch);
                occ -= rl;
                if (!pq.empty()) {
                    auto [ch2, occ2] = pq.top();
                    pq.pop();
                    ans += ch2;
                    if (occ2 > 1) {
                        pq.push({ch2, occ2 - 1});
                    }
                    pq.push({ch, occ});
                }
            } else {
                ans += string(occ, ch);
            }
        }
        return ans;
    }
};