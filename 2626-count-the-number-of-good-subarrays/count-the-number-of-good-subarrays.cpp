class Solution {
public:
    long long solve(vector<int>& nums, int k) {
        long long ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        long long cnt = 0;
        int l = 0;
        
        for (int r = 0; r < n; ++r) {
            if (mp[nums[r]] > 0) {
                cnt += mp[nums[r]];
            }
            mp[nums[r]]++;
            
            while (cnt >= k) {
                ans += (n - r);
                
                if (mp[nums[l]] > 1) {
                    cnt -= (mp[nums[l]] - 1);
                }
                mp[nums[l]]--;
                l++;
            }
        }
        return ans;
    }

    long long countGood(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};
