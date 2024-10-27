class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> temp(26,0);
        for(char c : s){
            if(temp[c-'a'] == 0) temp[c - 'a']++;
            else return c;
        }
    return 'f';
    }
};