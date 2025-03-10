class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num] += num;
        }

        vector<int> uniqueNums;
        for (auto& entry : freq) {
            uniqueNums.push_back(entry.first);
        }
        sort(uniqueNums.begin(), uniqueNums.end());

        int n = uniqueNums.size();
        vector<int> dp(n, 0);

        dp[0] = freq[uniqueNums[0]];

        for (int i = 1; i < n; ++i) {
            if (uniqueNums[i] == uniqueNums[i - 1] + 1) {
                dp[i] = max(dp[i - 1], (i > 1 ? dp[i - 2] : 0) + freq[uniqueNums[i]]);
            } else {
                dp[i] = dp[i - 1] + freq[uniqueNums[i]];
            }
        }
        return dp[n - 1];
    }
};