class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            int mask = nums[i];
            for(int j = i+1 ; j < n ; j++){
                if((mask & nums[j]) != 0) break;
                mask = mask | nums[j];
                ans = max(ans, j - i + 1);
            }
        }
    return ans;
    }
};