class Solution {
public:
    void change(string& s, char f,char ch){
        for(int i=0;i<s.length();i++){
            if(s[i] == f){
                s[i] = ch;
            }
        }
    }
    int minMaxDifference(int num) {
        int idx = 0;
        string s = to_string(num);
        string p = to_string(num);
        while(idx < s.length() && s[idx] == '9'){
            idx++;
        }

         if (idx < s.length()) {
            change(s, s[idx], '9');
        }
        change(p,p[0],'0');
        cout << s;
    return stoi(s) - stoi(p);
    }
};