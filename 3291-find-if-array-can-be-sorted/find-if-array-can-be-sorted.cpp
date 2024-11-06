class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int prevBitCnt = __builtin_popcount(nums[0]);
        int prevMax = 0, currMin = 0, currMax = 0;
        for(auto it : nums){
            int currBits = __builtin_popcount(it);
            if(currBits == prevBitCnt){
                prevBitCnt = currBits;
                currMin = min(currMin, it);
                currMax = max(currMax, it);
            }
            else{
                if(prevMax > currMin) return false;
                prevBitCnt = currBits;
                prevMax = currMax;
                currMin = it;
                currMax = it;
            }
        }
        if(prevMax > currMin) return false;
        return true;
    }
};