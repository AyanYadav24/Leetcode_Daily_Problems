class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = nums[0];
        int curr = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i])
                curr += nums[i];
            else{
                curr = nums[i];
            }
            maxi = max(curr,maxi);
        }
    return maxi;
    }
};