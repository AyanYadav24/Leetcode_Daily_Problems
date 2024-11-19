class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0, sum = 0;
        unordered_set<int> st;

        while (j < n) {
            if (st.find(nums[j]) == st.end()) {
                sum += nums[j];
                st.insert(nums[j]);
            } else {
                while (st.count(nums[j])) {
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                sum += nums[j];
                st.insert(nums[j]);
            }
            if (j - i + 1 == k) {
                ans = max(ans, sum);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};