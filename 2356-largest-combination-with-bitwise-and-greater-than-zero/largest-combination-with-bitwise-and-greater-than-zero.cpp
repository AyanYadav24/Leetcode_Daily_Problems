class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;
        for(int bit = 0; bit < 25 ; bit++){
            int currCnt = 0; //This represents number of set bits at current bit position
            for(auto num : candidates){
                if(num & (1 << bit)) currCnt++;
            }
            maxi = max(currCnt,maxi);
        }
    return maxi;
    }
};