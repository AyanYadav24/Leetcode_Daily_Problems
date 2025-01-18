class Solution {
public:
    int minimumLength(string s) {
       int n = s.length();
       int i=0,j=n-1;
       while(i<j){
        if(s[i] == s[j]){
            while(i+1<j and s[i] == s[i+1]) i++;
            while(i+1<j and s[j] == s[j-1]) j--;
        }
        else break;
        i++;j--;
       }
       return j-i+1;
    }
};