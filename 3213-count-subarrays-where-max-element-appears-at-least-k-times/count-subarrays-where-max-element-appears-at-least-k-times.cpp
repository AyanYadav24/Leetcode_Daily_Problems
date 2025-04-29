class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size() , l = 0, r = 0;
        int cnt = 0;
        long long ans = 0;
        while(r < n){
            if(nums[r] == maxi) cnt++;
            while(cnt >= k){
                if(nums[l] == maxi) cnt--;
                l++;
                ans += n-r;
            }
            r++;
        }
    return ans;
    }
};