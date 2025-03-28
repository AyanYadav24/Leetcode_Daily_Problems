class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int cnt = 0;
        int j = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == pivot) cnt++;
            else if(nums[i] < pivot) ans[j++] = nums[i];
        }
        for(int i=0;i<cnt;i++) ans[j++] = pivot;
        for(int i=0;i<n;i++){
            if(nums[i] > pivot) ans[j++] = nums[i];
        }
    return ans;
    }
};