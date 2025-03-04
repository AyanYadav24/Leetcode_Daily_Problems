class Solution {
public:
    bool solve(int p, int n, int stop, int sum) {
        if(sum > n) return false;

        if (p >= stop) return (sum == n);
    
        bool take     = solve(p + 1, n, stop, sum + pow(3, p));
        bool not_take = solve(p + 1, n, stop, sum);

        return take || not_take;
    }

    bool checkPowersOfThree(int n) {
        int stop = (log(n) / log(3)) + 1;
        int sum = 0;
        return solve(0, n, stop, sum);
    }
};
