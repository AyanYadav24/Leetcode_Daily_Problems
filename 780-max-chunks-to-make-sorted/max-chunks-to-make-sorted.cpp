class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int chunks = 1;
        int maxi = -1;
        for(int i=0;i<n-1;i++){
            maxi = max(arr[i],maxi);
            if(maxi == i) chunks++;
        }
    return chunks;
    }
};