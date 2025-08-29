class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, mc = 0, zc = 0, oc = 0;
        while(j < n) {
            if(nums[j] == 0) zc++;
            else oc++;
            while(zc > 1) {
                if(nums[i] == 0) zc--;
                else oc--;
                i++;
            }
            mc = max(oc,mc);
            j++;
        }
    return mc == n ? n-1 : mc;
    }
};