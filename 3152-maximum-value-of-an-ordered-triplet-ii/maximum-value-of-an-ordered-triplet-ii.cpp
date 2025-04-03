class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxDiff = 0, maxNum = 0, maxAns = 0;
        for(long num : nums){
            maxAns = max(maxAns,maxDiff * num);//77
            maxDiff = max(maxDiff,maxNum - num);//11
            maxNum = max(maxNum,num);//12
        }
    return maxAns;
    }
};