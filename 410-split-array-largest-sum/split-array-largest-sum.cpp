class Solution {
public:
    bool possible(int sum, vector<int>& nums, int k){
        int divs = 1;
        int curr_sum = 0;
        for(int i=0;i<nums.size();i++){
            if(curr_sum + nums[i] <= sum){
                curr_sum += nums[i];
            }
            else{
                divs++;
                if(divs > k || nums[i] > sum) return false;
                curr_sum = nums[i];
            }
        }
    return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int s = 0;
        int e = total;
        int ans = -1;

        while(s <= e){
            int m = s + (e - s) / 2;
            if(possible(m,nums,k)){
                ans = m;
                e = m - 1;
            }
            else{
                s = m + 1;
            }
        }
    return ans;
    }
};