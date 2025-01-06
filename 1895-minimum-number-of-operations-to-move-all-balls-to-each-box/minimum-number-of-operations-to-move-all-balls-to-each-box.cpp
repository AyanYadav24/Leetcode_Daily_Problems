class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        unordered_set<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(s[i] == '1') st.insert(i);
        }
        for(int i=0;i<n;i++){
            int val = 0;
            for(int pos : st){
                val += abs(i - pos);
            }
            ans[i] = val;
        }
    return ans;
    }
};