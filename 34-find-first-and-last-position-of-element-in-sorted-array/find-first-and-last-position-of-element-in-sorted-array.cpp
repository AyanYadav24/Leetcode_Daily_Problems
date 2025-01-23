class Solution {

private:
    int firstPosition(vector<int>& nums, int t){
        int low, mid, high;
        int ans = -1;
        low= 0;
        high = nums.size() - 1;

        while(low<=high){
            mid = (high + low)/2;
            if(nums[mid] == t){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid]> t){
                high = mid - 1;
            }
            else if(nums[mid]< t){
                low = mid + 1;
            }
        }
        return ans;
    }
private:
    int lastPosition(vector<int>& nums, int t){
        int low, mid, high;
        int ans = -1;
        low= 0;
        high = nums.size() - 1;

        while(low<=high){
            mid = (high + low)/2;
            if(nums[mid] == t){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid]> t){
                high = mid - 1;
            }
            else if(nums[mid]< t){
                low = mid + 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPosition(nums, target);
        int last = lastPosition(nums, target);

        return {first, last};
    }
};