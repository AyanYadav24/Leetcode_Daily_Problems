class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxsum = 0, curr = 0;
        int n = nums.size(), i = 0, j = 0;
        map<int, int> mp;
        while (j < n) {
            mp[nums[j]]++;
            curr += nums[j];
            cout<<curr<<endl;
            if (j - i + 1 == k) {
                if (mp.size() == k) {
                    maxsum = max(maxsum, curr);
                }
                curr -= nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxsum;
    }
};