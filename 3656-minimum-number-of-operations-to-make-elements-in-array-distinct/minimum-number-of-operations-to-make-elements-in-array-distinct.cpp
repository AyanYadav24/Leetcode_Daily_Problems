class Solution {
public:
    bool unique(vector<int>& hash) {
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] > 1) return false;
        }
        return true;
    }
    
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(101, 0);
        
        for (int num : nums)
            hash[num]++;
        
        int ans = 0;
        int idx = 0;

        while (!unique(hash)) {
            int count = 3;
            while (idx < n && count-- > 0) {
                hash[nums[idx]]--;
                idx++;
            }
            ans++;
        }
    return ans;
    }
};
