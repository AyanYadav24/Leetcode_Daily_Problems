class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string comp = "";
        for(int i=0;i<n;i++){
            int cnt = 1;
            while(cnt <= 8 && i+1 < n && word[i] == word[i+1]){
                cnt++;
                i++;
            }
            comp += to_string(cnt) + word[i];
        }
        return comp;
    }
};