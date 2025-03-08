class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int i=0,j=0,cnt=0,ans=INT_MIN;
        while(j<n){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') cnt++;
            if(j-i+1 == k){
                ans = max(ans,cnt);
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt--;
                i++;
            }
            j++;
        }
    return ans;
    }
};