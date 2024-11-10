class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<pair<int,string>> comb;
        for(int i=0;i<n;i++){
            comb.push_back({heights[i],names[i]});
        }

        sort(begin(comb),end(comb),greater<>());

        vector<string> ans;
        
        for(auto i : comb){
            ans.push_back(i.second);
        }
    return ans;
    }
};