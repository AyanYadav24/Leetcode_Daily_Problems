class Solution {
public:
    bool isSubset(vector<int> f2, vector<int> temp){
        for(int i=0;i<26;i++){
            if(f2[i] > temp[i]) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f2(26,0);
        for(string &word : words2){
            vector<int> temp(26,0);
            for(char c : word){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++){
                f2[i] = max(temp[i],f2[i]);
            }
        }
        vector<string> ans;
        for(const auto& word : words1){
            vector<int> temp(26,0);
            for(char c : word){
                temp[c-'a']++;
            }
            if(isSubset(f2,temp)) ans.push_back(word) ;
        }
    return ans;
    }
};