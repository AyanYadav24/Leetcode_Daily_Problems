class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = 0, len = 0, i = 0;

        while (i < nums.size()) {
            while (nums[i] - nums[j] > 1) {
                ++j;
            }
            if (nums[i] - nums[j] == 1) {
                len = max(len, i - j + 1);
            }
            i++;
        }
        return len;
    }
};