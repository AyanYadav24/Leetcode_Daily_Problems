class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        bool ans = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i && arr[i] == 2 * arr[j]) ans = true;
            }
        }
    return ans;
    }
};