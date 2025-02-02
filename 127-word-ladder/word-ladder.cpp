class Solution {
public:
    int ladderLength(string b, string e, vector<string>& word) {
        unordered_set<string> st(word.begin(),word.end());

        if(st.find(e) == st.end()) return 0;

        queue<pair<string,int>> q;
        q.push({b,1});
        while(!q.empty()){
            auto it = q.front();
            string s = it.first;
            int num = it.second;
            q.pop();
            for(int i=0;i<s.size();i++){
                for(int j=0;j<26;j++){
                    char ch = s[i];
                    s[i] = j + 'a';
                    if(st.find(s) != st.end()){
                        if(s == e) return num+1;
                        st.erase(s);
                        q.push({s,num+1});
                    }
                    s[i] = ch;
                }
            }
        }
    return 0;
    }
};