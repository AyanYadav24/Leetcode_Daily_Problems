class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int ans = 0;
        int i = 0;
        while(i<nums.size()){
            int c = nums[i];
            while( i < nums.size() && nums[i] - c <= k) i++;
            ans++;
        }
    return ans;
    }
};