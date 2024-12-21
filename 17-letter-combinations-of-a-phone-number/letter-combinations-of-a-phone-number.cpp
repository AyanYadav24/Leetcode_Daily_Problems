class Solution {
private:
    void solve(int ind, string digits, vector<string>& ans, string mapping[],string output){
        //Base case
        if(ind >= digits.size()){
            ans.push_back(output);
            return;
        }

        int num = digits[ind] - '0';
        cout << num;
        string mapped_string = mapping[num];

        for(int i=0;i<mapped_string.length();i++){
            output += mapped_string[i];
            solve(ind+1,digits,ans,mapping,output);
            //backtracking -> remove character added by the last call while returning back to previous state
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string output = "";
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,ans,mapping,output);
    return ans;
    }
};