class Solution {
public:
    bool isValid(string word) {
        unordered_set<char> vowels = {'a', 'e' , 'i' , 'o' , 'u'};
        bool hasVowel = false , hasConsonant = false;
        if(word.length() < 3) return false;
        for(char c : word){
            if(!isalnum(c)) return false;
            c = tolower(c);
            if(vowels.contains(c)) hasVowel = true;
            else if(!isdigit(c)) hasConsonant = true;
        }
        return hasVowel && hasConsonant;
    }
};