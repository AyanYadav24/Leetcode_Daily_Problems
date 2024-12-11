class Solution {
public:
    int binary_search(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int res = 0;
        while(s <= e){
            int mid = s + (e-s) / 2;
            if(nums[mid] <= target){
                res = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        return res;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int maxi = 0;

        for(int i=0; i<nums.size(); i++){
            int y = nums[i] + 2*k;

            int ind = binary_search(nums,y);
            maxi = max(maxi,ind - i + 1);
        }
        return maxi;
    }
};