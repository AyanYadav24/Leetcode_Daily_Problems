class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] - 'a' < 0 && !st.empty()) st.pop();
            else st.push(s[i]);
            cout << s[i] - 'a' << " ";
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};