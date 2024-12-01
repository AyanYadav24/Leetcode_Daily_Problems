class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        bool ans = false;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(2 * arr[i] == arr[j] || arr[i] == 2 * arr[j]) ans = true;
            }
        }
       return ans;
    }
};