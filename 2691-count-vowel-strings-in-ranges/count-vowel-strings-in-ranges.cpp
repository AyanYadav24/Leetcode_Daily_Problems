class Solution {
public:
    bool isVowel(char& ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();
        int Q = queries.size();

        vector<int> cumVowels(N);
        int cumV = 0;
        for(int i=0;i<N;i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
               cumV++;
            }
            cumVowels[i] = cumV;
        }
        vector<int> ans(Q);
        for(int i=0;i<Q;i++){
            int first = queries[i][0];
            int sec = queries[i][1];

            ans[i] = cumVowels[sec] - ((first >  0) ? cumVowels[first - 1] : 0);
        }
        return ans;
    }
};