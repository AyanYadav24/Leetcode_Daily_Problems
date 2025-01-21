class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum  = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRowSum = 0LL;
        long long ans = LONG_LONG_MAX;

        for(int i=0;i<grid[0].size();i++){
            firstRowSum-=grid[0][i];
            long long curr_ans = max(firstRowSum,secondRowSum);
            secondRowSum += grid[1][i];
            ans = min(curr_ans,ans);
        }
        return ans;
    }
};