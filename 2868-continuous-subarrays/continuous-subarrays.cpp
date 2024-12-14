class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> mp;
        long long cnt = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            mp[nums[j]]++;
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt += (j - i + 1);
        }
        return cnt;
    }
};
