class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = sortString(to_string(n));
        for (int i = 0; i < 31; ++i) {
            string powerStr = sortString(to_string(1 << i));
            if (s == powerStr) return true;
        }
        return false;
    }
    
    string sortString(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};
