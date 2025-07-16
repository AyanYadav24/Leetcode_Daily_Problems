class Solution {
public:
    bool isValid(string word) {
        bool hasVowel = false , hasConsonant = false;
        if(word.length() < 3) return false;
        for(char c : word){
            if(!isalnum(c)) return false;
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u') hasVowel = true;
            else if(!isdigit(c)) hasConsonant = true;
        }
        return hasVowel && hasConsonant;
    }
};