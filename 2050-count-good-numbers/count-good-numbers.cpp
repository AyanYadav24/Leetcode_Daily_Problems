class Solution {
public:
    const int MOD = 1e9 + 7; 

    long long power(long long base, long long exp){
        if(exp == 0) return 1;
        long long ans = power(base,exp/2);
        ans = (ans * ans) % MOD;

        if(exp % 2 != 0) ans = (ans * base) % MOD;
        return ans; 
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
    return (power(5,even) * power(4,odd)) % MOD;
    }
};