class Solution {
public:
    bool solve(int idx, vector<int>& arr, vector<bool>& vis){
        if(idx >= arr.size() || idx < 0) return false;
        if(arr[idx] == 0) return true;
        if(vis[idx]) return false;

        vis[idx] = true;

        if(solve(idx + arr[idx],arr,vis) || solve(idx - arr[idx],arr,vis))
            return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),false);
        return solve(start,arr,vis);
    }
};