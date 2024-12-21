class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length() - 1;
        while (i > 0) {
            if (s[i] > s[i - 1]) {
                int j = s.length() - 1;
                while (s[i - 1] >= s[j])
                    j--;
                swap(s[i - 1], s[j]);
                reverse(s.begin() + i, s.end());
                long long ans = stoll(s);
                if (ans > INT_MAX) {
                    return -1;
                }
                return ans;
            }
            i--;
        }
        return -1;
    }
};