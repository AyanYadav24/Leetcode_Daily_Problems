class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size() / 3;
        vector<vector<int>> res;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i+=3){
            if(nums[i+2] - nums[i] <= k){
                res.emplace_back(nums.begin() + i , nums.begin() + i + 3);
            }
        }
        if(res.size() != nums.size() / 3) return {};
        return res;
    }
};