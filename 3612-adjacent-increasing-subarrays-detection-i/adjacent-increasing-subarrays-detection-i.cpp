class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i <= n - 2 * k; i++) {
            bool check = true;
            
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    check = false;
                    break;
                }
            }
            
            if(check){
                for (int j = i + k; j < i + 2 * k - 1; j++) {
                    if (nums[j] >= nums[j + 1]) {
                        check = false;
                        break;
                    }
                }
            }
            
            if (check) {
                return true;
            }
        }
        
        return false;
    }
};
