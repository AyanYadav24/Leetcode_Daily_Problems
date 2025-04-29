class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size() , l = 0 , r = 0;
        int sum = 0 , cnt = 0;
        while(r < n){
            sum += nums[r];

            if(r-l+1 == 3){
                if((sum - nums[r-1]) * 2 == nums[r-1]) cnt++;
                sum -= nums[l];
                l++;
            }

            r++;
        }
        return cnt;
    }
};