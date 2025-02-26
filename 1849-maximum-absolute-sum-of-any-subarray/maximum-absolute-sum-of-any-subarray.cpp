class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int global_max = 0;
        int curr_max = 0;

        for(int i = 0; i < nums.size(); i++){
            curr_max += nums[i];
            curr_max = max(nums[i], curr_max);
            global_max = max(curr_max, global_max);
        }

        int global_min = 0;
        int curr_min = 0;

        for(int i = 0; i < nums.size(); i++){
            curr_min += nums[i];
            curr_min = min(nums[i], curr_min);
            global_min = min(curr_min, global_min);
        }
        cout << global_min;
        return max(abs(global_min),global_max);
    }
};