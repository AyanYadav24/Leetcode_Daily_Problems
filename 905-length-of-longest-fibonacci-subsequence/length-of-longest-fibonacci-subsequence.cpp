class Solution {
public:
    int ans = 0;

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        
        unordered_map<int, unordered_map<int, int>> dp;
        int curr = 2;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (index.find(arr[i] + arr[j]) != index.end()) {
                    int k = index[arr[i] + arr[j]];
                    dp[j][k] = dp[i][j] + 1;
                    ans = max(ans, dp[j][k] + 2);
                }
            }
        }

        return ans >= 3 ? ans : 0;
    }
};
