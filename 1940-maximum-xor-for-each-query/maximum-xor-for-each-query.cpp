class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans;
        int xr = 0;

        int mask = (1 << maximumBit) - 1; // set bits of n size
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(xr ^ mask); // for maximizing xor we need flip of given number
            xr ^= nums[n - 1 - i];
        }
        return ans;
    }
};