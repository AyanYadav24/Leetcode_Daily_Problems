class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int l=0,r=0,cnt=0;
        unordered_map<int,int> mp;

        while(r<n){
            mp[nums[r]]++;
            while(mp.size() > k){
                if(--mp[nums[l]] == 0) mp.erase(nums[l]); 
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
       return solve(arr,k) - solve(arr,k-1);
    }
};