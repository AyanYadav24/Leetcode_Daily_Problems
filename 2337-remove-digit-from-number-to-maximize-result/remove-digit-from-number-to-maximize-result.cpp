class Solution {
public:
    string removeDigit(string number, char digit) {
        string temp = number;
        string ans = "";
        for(int i=0;i<number.length();i++){
            if(number[i] == digit){
                temp.erase(i,1);
                ans = max(ans,temp);
            }
            temp = number;
        }
        return ans;
    }
};