class Solution {
public:
   
    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0, pairs = 0, n = nums.size();
        long long res = 0;
        unordered_map<int, int> freq;
        while(r < n){
            freq[nums[r]]++;
            pairs += freq[nums[r]]-1;

            while(l < n && pairs >= k){
                res += n - r;
                pairs -= freq[nums[l]]-1;
                freq[nums[l]]--;
                l++;
            }
            r++;
        }
        return res;
    }
};