class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }
private:   
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        if(start == nums.size()){
            result.push_back(path);
            return;
        }
        path.push_back(nums[start]);
        backtrack(nums,start+1,path,result);
        path.pop_back();
        backtrack(nums,start+1,path,result);
    }
};