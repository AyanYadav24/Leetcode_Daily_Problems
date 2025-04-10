class Solution {
public:
    long long no_of_powerful_numbers(string num, int limit, string s){
        if(num.length() < s.length()) return 0;
        int len = num.length() - s.length();
        long long ans = 0;

        string remNum = num.substr(len);
        for(int i=0;i<len;i++){
            int digit = num[i] - '0';
            if(digit <= limit){
                ans += digit * pow(limit+1,len-i-1);
            }
            else{
                ans += pow(limit+1,len-i);
                return ans;
            }
        }
        if(remNum >= s) ans++;
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string strt = to_string(start-1);
        string end  =  to_string(finish);
        return no_of_powerful_numbers(end,limit,s) - no_of_powerful_numbers(strt,limit,s);
    }
};