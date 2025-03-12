class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;

        int ub = upper_bound(nums.begin(),nums.end(),0) - nums.begin();
        int lb = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        cout << lb << " " << n - ub;
    return max(lb,n-ub);
    }
};