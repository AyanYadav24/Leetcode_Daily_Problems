class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    bool backtrack(const string& digits, vector<bool>& used, int curr, int count) {
        if (count == digits.size()) return isPowerOfTwo(curr);

        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue;

            if (curr == 0 && digits[i] == '0') continue;

            int newNum = curr * 10 + (digits[i] - '0');
            used[i] = true;

            if (backtrack(digits, used, newNum, count + 1)) return true;

            used[i] = false;
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        string digits = to_string(n);
        vector<bool> used(digits.size(), false);

        return backtrack(digits, used, 0, 0);
    }
};
