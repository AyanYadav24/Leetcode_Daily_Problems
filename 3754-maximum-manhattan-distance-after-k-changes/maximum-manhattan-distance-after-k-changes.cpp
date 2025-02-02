class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDis = 0;
        vector<vector<char>> diagonals = {
            {'N', 'E'}, 
            {'N', 'W'}, 
            {'S', 'E'}, 
            {'S', 'W'}
        };
        // Try going in all of the four directions -> kisi bhi trf max ho skta h
        for (auto diag : diagonals) {
            int tempK = k;
            int dist = 0;

            for (char ch : s) {
                if (ch == diag[0] || ch == diag[1]) {
                    dist++;
                } else if (tempK > 0) { // agr is bar wale directions se alg direction hui to ek k use hojaega
                    dist++;
                    tempK--;
                } else {  // agr sare k khtm ho gye aur direction bhi koi alg h to decrease hi hogi distance
                    dist--;
                }
                maxDis = max(maxDis, dist); // hr step pe max dist calculate krna h
            }
        }
        return maxDis;
    }
};