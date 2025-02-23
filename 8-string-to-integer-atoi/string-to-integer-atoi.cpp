class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long long int num = 0;
        bool neg = false;
        int i = 0;
        while(i<n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-') neg = true;
            i++;
        }
        while (i < n) {
            if(isdigit(s[i])) {
                num = (num * 10 + s[i] - '0');
                if(!neg && num > INT_MAX) return INT_MAX;
                if(neg && num > INT_MAX)  return INT_MIN;
            }
            else break;
            i++;
        }
        if(neg) num = -1*num;
    return num;
    }
};