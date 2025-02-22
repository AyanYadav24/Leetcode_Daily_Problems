class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;
        int i=n-1;
        while(i>=0){
            while(i>=0 && s[i] == ' ') i--;
            string word = "";
            while(i>=0 && s[i] != ' '){ word += s[i]; i--;}
            reverse(word.begin(),word.end());
            ans += word + " ";
        }
        n = ans.length();
        i = n-1;
        while(i>=0 && ans[i] == ' '){ ans.pop_back(); i--;}
    return ans;
    }
};