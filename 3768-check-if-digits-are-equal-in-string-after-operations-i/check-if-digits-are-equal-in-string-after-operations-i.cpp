class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        while (n > 2) {
            string new_s = "";
            for (int i = 1; i < n; i++) {
                int sum = (s[i - 1] - '0') + (s[i] - '0');
                new_s += to_string(sum % 10);
            }
            s = new_s;
            n = s.length();
        }
        return s[0] == s[1];
    }
};