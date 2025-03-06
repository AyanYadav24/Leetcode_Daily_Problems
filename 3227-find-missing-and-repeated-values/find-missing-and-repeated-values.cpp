class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n = grid.size();
       n *= n;
       long long S = 0, S2 = 0;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            S  += grid[i][j];
            S2 += grid[i][j]*grid[i][j];
        }
       }
       long long Sn  = n*(n+1)/2;
       long long S2n = n*(n+1)*((long long)2*n+1)/6;
       int val1 =  S - Sn; //rep - miss
       int val2 = (S2 - S2n) / (val1); // rep + miss -> (use of a^2 - b^2 = (a+b)(a-b))
       int repeating = (val1 + val2) / 2;
       int missing   = val2 - repeating ;
    return {repeating,missing}; 
    }
};