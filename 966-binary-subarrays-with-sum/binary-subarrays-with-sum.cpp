class Solution {
public:
    int sumLessthanEqualTo_k(vector<int> arr,int k,int n){
        int l=0,r=0,sum=0,cnt=0;
        while(r<n){
            sum+=arr[r];
            while(sum>k && l<=r){
                sum-=arr[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& arr, int k) {
        int n = arr.size();
        cout<<sumLessthanEqualTo_k(arr,k,n);
        int ans = sumLessthanEqualTo_k(arr,k,n) - sumLessthanEqualTo_k(arr,k-1,n);
        return ans;
        




        // while(r<n){
        //     sum+=arr[r];
        //     if(sum==k){
        //          cnt++;
        //          int temp = l;
        //         while (temp < r && sum == k) {
        //             cnt++;
        //             sum -= arr[temp++];
        //         }
        //     }
        //     r++;
        // }
        // return cnt;
    }
};