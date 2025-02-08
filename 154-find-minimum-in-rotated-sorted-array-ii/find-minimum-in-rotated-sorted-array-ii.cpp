class Solution {
public:
    int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] > arr[high]){
            low = mid + 1;
        }
        else if(arr[mid] < arr[high]){
            high = mid;
        }
        else high--;
    }
    return arr[low];
    }
};