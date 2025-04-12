class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> palindromes;

        int d = (n+1) / 2;
        int left = pow(10 , d-1), right = pow(10 , d) - 1;

        for(int i=left ; i<=right ; i++){
            string full_string = "" , r_string = "";
            string l_string = to_string(i);

            if(n % 2){
                r_string = l_string.substr(0, d - 1);
            }
            else{
                r_string = l_string;
            }
            reverse(r_string.begin(),r_string.end());
            full_string = l_string + r_string;
            long long num = stoll(full_string);

            if(num % k != 0) continue;

            sort(full_string.begin(),full_string.end());
            palindromes.insert(full_string);
        }

        vector<int> fact(11,1);
        for(int i = 1 ; i <= 10 ; i++){
            fact[i] = fact[i-1] * i;
        }

        long long ans = 0;
        for(auto& str : palindromes){
            vector<int> cnt(10);
            for(auto ch : str) cnt[ch -'0']++;

            int digits_cnt   = str.size();
            int zero_cnt     = cnt[0];
            int non_zero_cnt = digits_cnt - zero_cnt;

            long long perms = (non_zero_cnt) * fact[n - 1];

            for(int i : cnt){
                perms /= fact[i];
            }
            ans += perms;
        }
    return ans;
    }
};