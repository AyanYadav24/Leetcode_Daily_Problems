class Solution {
public:
    bool isPossible(int val, vector<int>& nums, int k){
        int i = 0, cnt = 0;
        while(i < nums.size()){
            if(nums[i] <= val){
                cnt++;
                i+=2;
            }
            else i++;
            if(cnt >= k) return true;
        }
    return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());

        int ans = -1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(isPossible(mid,nums,k)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
    return ans;
    }
};