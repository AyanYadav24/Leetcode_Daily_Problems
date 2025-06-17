class Solution {
private:
    void change(string& s, char f,char ch){
        for(int i=0;i<s.length();i++){
            if(s[i] == f){
                s[i] = ch;
            }
        }
    }
public:
    int maxDiff(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);

        int idx = 0;
        while(idx < s1.length() && s1[idx] == '9'){
            idx++;
        }
        if(idx < s1.length()) change(s1,s1[idx],'9');

        //second operation
        for(int i=0;i<s2.length();i++){
            char c = s2[i];
            if(i==0 && s2[i] != '1'){
                change(s2,s2[i],'1');
                break;
            }
            else if(c!='0' && c!=s2[0]){
                change(s2,c,'0');
                break;
            }
        }
        cout << s1 << " " << s2;
    return stoi(s1) - stoi(s2);
    }
};