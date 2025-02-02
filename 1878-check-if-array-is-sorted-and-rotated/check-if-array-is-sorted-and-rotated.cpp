class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
       for(int i=0;i<nums.size();i++){
        if(nums[i] > nums[(i+1)%n]) cnt++;
       }
       return cnt == 0 || cnt == 1;
    }
};