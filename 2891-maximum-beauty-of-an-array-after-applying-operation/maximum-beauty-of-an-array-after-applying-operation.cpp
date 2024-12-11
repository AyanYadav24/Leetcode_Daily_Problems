class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));

        int j=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            while( j < nums.size() && nums[j] <= nums[i] + 2*k) j++;
            maxi = max(maxi,j-i);
        }
        return maxi;
    }
};