class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(begin(vec),end(vec),greater<pair<int,int>>());
        vector<pair<int,int>> ans;
        for(int i=0;i<k;i++){
            int ind = vec[i].second;
            int num = vec[i].first;
            ans.push_back({ind,num});
        }
        sort(begin(ans),end(ans));
        vector<int> r;
        for(auto it : ans) r.push_back(it.second);
    return r;
    }
};