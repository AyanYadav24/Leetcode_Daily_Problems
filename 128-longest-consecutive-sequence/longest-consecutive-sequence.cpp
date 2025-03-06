class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> temp;
        
        for (int num : nums) {
            if (temp.find(num) == temp.end()) {
                int left = temp.count(num - 1) ? temp[num - 1] : 0;
                int right = temp.count(num + 1) ? temp[num + 1] : 0;
                int curr = left + right + 1;
                
                temp[num] = curr;
                ans = max(ans, curr);
                
                if (left) {
                    temp[num - left] = curr;
                }
                if (right) {
                    temp[num + right] = curr;
                }
            }
        }
        return ans;
    }
};
