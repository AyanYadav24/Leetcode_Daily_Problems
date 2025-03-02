class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int zero = 0;
        int n = nums.size();
        vector<int> v;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0) v.push_back(nums[i]);
            else zero++;
        }
        for(int i=0;i<zero;i++){
            v.push_back(0);
        }
        return v;
    }
};