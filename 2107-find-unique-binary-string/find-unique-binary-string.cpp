class Solution {
public:
    bool solve(string& ans, string& curr, int n, unordered_set<string>& st){
        if(curr.size() == n){
            if(st.find(curr) == st.end()){
                ans = curr;
                return true;
            } 
            return false;
        }

        // for(int i=0;i<n;i++){
            for(char c = '0' ; c<= '1' ; c++){
            curr += c;
            if(solve(ans,curr,n,st)) return true;
            curr.pop_back();
            }
        // }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        for(string s : nums){
            st.insert(s);
        }

        string curr = "";
        string ans = "";
        solve(ans,curr,n,st);
        return ans;
    }
};