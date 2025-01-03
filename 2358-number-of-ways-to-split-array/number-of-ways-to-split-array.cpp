class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i];

        long long curr_sum = 0;
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            curr_sum += nums[i];
            if(curr_sum >= sum - curr_sum) cnt++;
        }
    return cnt;
    }
};