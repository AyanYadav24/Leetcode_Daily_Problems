class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prev(n,0);
        prev[0] = nums[0];
        for(int i=1;i<n;i++){
            prev[i] = prev[i-1] + nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i] = ((nums[i] * (i+1)) - prev[i]) + ((prev[n-1] - prev[i]) - (nums[i] * (n-i-1)));
        }
        return ans;
    }
};