class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;
        for (int i = 0; i < nums.size(); i++) {
            int rem = (nums[i] % value + value) % value;
            freq[rem]++;
        }
        int MEX = 0;
        while (freq[MEX % value] > 0) {
            freq[MEX % value]--;
            MEX++;
        }
        return MEX;
    }
};
