class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> ones(n);
        int one = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1') one++;
          ones[i] = one;
        }
        int ans = 0;
        int zeroes = 0;
        for(int i=0;i<n-1;i++){
            if(s[i] == '0') zeroes++;
         ans = max(ans,zeroes + ones[i+1]);
        }
    return ans;
    }
};