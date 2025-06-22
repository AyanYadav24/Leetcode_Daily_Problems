class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        int m = n % k , i = 0;

        while(i < n){
            if(i + k - 1 < n) {
                ans.push_back(s.substr(i,k));
            }
            else {
                string temp = s.substr(i,m);
                temp.append(k-m,fill);
                ans.push_back(temp);
            }
            i += k;
        }
        return ans;
    }
};