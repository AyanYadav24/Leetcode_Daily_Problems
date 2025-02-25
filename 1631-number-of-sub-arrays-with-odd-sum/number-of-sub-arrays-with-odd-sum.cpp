class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd_cnt  = 0, even_cnt = 1, curr_sum = 0, ans = 0, mod = 1e9 + 7;
        for(int num : arr){
            curr_sum += num;
            if(curr_sum % 2 == 0){
                ans = (ans + odd_cnt) % mod;
                even_cnt++;
            }
            else{
                ans = (ans + even_cnt) % mod;
                odd_cnt++;
            }
        }
        return ans;
    }
};