class Solution {
public:
    void sum(int i, int target, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans, int n) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int j = i; j < n; j++) {
            if (j != i && arr[j] == arr[j - 1]) continue; 
            if (arr[j] > target) break;
            curr.push_back(arr[j]);
            sum(j, target - arr[j], arr, curr, ans, n); 
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); 
        int n = candidates.size();
        sum(0, target, candidates, curr, ans, n);
        return ans;
    }
};