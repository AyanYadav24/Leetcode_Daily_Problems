class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) 
            return false;
        if (n == 2) 
            return true;
        if (n % 2 == 0) 
            return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) 
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int a = -1, b = -1;
        int minDiff = INT_MAX;
        int prev = -1;
        
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (prev != -1) {
                    int diff = i - prev;
                    if(diff <= 2 ) return {prev,i};
                    if (diff < minDiff) {
                        minDiff = diff;
                        a = prev;
                        b = i;
                    }
                }
                prev = i;
            }
        }
        return {a, b};
    }
};
