class Solution {
public:
    void lcs(vector<int> arr,vector<int>& dp1,vector<int> &dp2,int n){
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(arr[pre] < arr[i] && 1 + dp1[pre] > dp1[i])
                    dp1[i] = 1 + dp1[pre];
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int pre=n-1;pre>i;pre--){
                if(arr[pre] < arr[i] && 1 + dp2[pre] > dp2[i])
                    dp2[i] = 1 + dp2[pre];
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        lcs(nums,dp1,dp2,n);
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(dp1[i] == 1 || dp2[i] == 1) continue;
            maxi = max(maxi , dp1[i] + dp2[i] -1);
        }
    return n-maxi;
    }
};