class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = INT_MAX, ans = 0;
        for(int i=1;i<nums.size();i++){
            mini = min(nums[i-1],mini);
            ans = max(ans,nums[i] - mini);
        }
    return ans == 0 ? -1 : ans;
    }
};