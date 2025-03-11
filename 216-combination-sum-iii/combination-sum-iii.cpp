class Solution {
public:
    void solve(int idx, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans, int k, int tar){
        if(idx == arr.size()){
            if(temp.size() == k && tar == 0) ans.push_back(temp);
            return;
        }
        temp.push_back(arr[idx]);
        solve(idx+1,arr,temp,ans,k,tar-arr[idx]);
        temp.pop_back();
        solve(idx+1,arr,temp,ans,k,tar);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,arr,temp,ans,k,n);
        return ans;
    }
};