class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (i + 2 < nums.size()) {
                    ans++;
                    for (int j = i; j <= i + 2; j++) {
                        nums[j] = (nums[j] == 0) ? 1 : 0;
                    }
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};
