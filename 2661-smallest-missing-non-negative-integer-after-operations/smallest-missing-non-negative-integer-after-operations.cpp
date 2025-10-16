class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;
        for (int i = 0; i < nums.size(); i++) {
            int rem = (nums[i] % value + value) % value;
            freq[rem]++;
        }
        int i = 0;
        while (true) {
            int rem = i % value;
            if (freq[rem] > 0) {
                freq[rem]--;
            } else {
                return i;
            }
            i++;
        }
        return -1;
    }
};
