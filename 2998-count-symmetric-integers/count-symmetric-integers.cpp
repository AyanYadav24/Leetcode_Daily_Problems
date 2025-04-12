class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low; i<=high; i++){
            string num = to_string(i);
            int n = num.length();
            if(n % 2 == 0){
                int j = 0, k = n-1, lsum = 0, rsum = 0;
                while(j < k){
                    lsum += num[j] - '0';
                    rsum += num[k] - '0';
                    j++;
                    k--;
                }
                if(lsum == rsum) ans++;
            }
        }
    return ans;
    }
};