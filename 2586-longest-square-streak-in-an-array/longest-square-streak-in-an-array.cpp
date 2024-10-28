class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> st(nums.begin(), nums.end());
        int maxStreak = -1;
        for (auto num : st) {
            int currStreak = 0;
            while (st.find(num) != st.end()) {
                currStreak++;
                num *= num;
            }

            if (currStreak >= 2) {
                maxStreak = max(maxStreak, currStreak);
            }
        }
        return maxStreak;
    }
};