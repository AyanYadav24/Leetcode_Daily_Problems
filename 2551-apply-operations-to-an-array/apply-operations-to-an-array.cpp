class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int i=0;
        int j=1;
        while(i<n && j<n){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i++],nums[j++]);
            }
            else if(nums[i]==0 && nums[j]==0){
                j++;
            }
            else{
                i++;j++;
            }
        }
        return nums;
    }
};