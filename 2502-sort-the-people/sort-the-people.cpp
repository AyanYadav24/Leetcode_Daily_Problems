class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<pair<int,string>> chumt;
        for(int i=0;i<n;i++){
            chumt.push_back({heights[i],names[i]});
        }

        sort(begin(chumt),end(chumt),greater<>());

        vector<string> ans;
        
        for(auto i : chumt){
            ans.push_back(i.second);
        }
    return ans;
    }
};