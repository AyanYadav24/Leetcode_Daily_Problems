class Solution {
public:
    const int MOD = 1E9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers,ans;
        int power = 0;
        while(n>0) {
            if(n & 1) powers.push_back(1 << power);
            n >>= 1;
            power++;
        }

        for(auto pair : queries) {
            int l = pair[0];
            int r = pair[1];

            long long product = 1;
            for(int i=l ; i<=r ; i++){
                product = (product * powers[i]) % MOD;
            }
            ans.push_back(product);
        }
        return ans;
    }
};