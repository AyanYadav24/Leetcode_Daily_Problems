class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int incm = 1,decm = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                decm++;
                incm = 1;
            }
            else if(nums[i] > nums[i-1]){
                incm++;
                decm = 1;
            }
            else{
                incm = 1;
                decm = 1;
            }
            ans = max({ans,decm,incm});
        }
        return ans;
    }
};