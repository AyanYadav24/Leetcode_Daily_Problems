class Solution {
public:
    bool hasSameDigits(string s) {
        for (int n = size(s); n > 2; n--) {
            for (int i = 0; i < n - 1; i++) {
                s[i] = ((s[i] + s[i + 1] - 2 * '0') % 10) + '0';
            }
        }
        return s[0] == s[1];
    }
};