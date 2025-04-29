class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long sum = 0, res = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] % m == k) nums[i] = 1;
            else nums[i] = 0;
        }
        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int r1 = sum % m;
            int r2 = (r1 - k + m) % m;

            res += mp[r2];
            mp[r1]++;
        }
    return res;
    }
};
