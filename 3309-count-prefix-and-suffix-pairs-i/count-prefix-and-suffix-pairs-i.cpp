class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;

        for (int i = 0; i < n1; i++) {
            if (s1[i] != s2[i]) return false; // Prefix mismatch
        }
        
        for (int i = 0; i < n1; i++) {
            if (s1[i] != s2[n2 - n1 + i]) return false; // Suffix mismatch
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
