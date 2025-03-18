class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, ans = 1, mask = 0;
        while(j < n){
            cout << mask << endl;
            while(i < n && (mask & nums[j]) != 0){
                mask ^= nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            mask |= nums[j];
            j++;
        }
    return ans;
    }
};