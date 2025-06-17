class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() , sum = 0,l = 0, r = 0, ans = INT_MAX;
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                ans = min(r-l+1,ans);
                sum -= nums[l];
                l++;
            }
            r++;
        }
    return ans == INT_MAX ? 0 : ans;
    }
};