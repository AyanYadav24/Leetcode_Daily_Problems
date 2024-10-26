class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char,int> mp;
        vector<int> temp(26,0);
        for(char c : s){
            temp[c-'a']++;
        }
        for(int i=0;i<s.size();i++ ){
            if(temp[s[i] - 'a'] == 1) return i;
        }

    return -1;
    }
};