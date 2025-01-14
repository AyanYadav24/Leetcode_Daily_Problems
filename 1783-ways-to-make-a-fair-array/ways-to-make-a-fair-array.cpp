class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        int evenTotalSum = 0, oddTotalSum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) evenTotalSum += nums[i];
            else oddTotalSum += nums[i];
        }

        int evenLeftSum = 0, oddLeftSum = 0;

        for (int i = 0; i < n; i++) {
           if(i%2 == 0)
            evenTotalSum -= nums[i];
           else
            oddTotalSum -= nums[i];

           if(evenLeftSum + evenTotalSum == oddLeftSum + oddTotalSum) cnt++;

           if(i%2 == 0)
            evenTotalSum -= nums[i];
           else
            oddTotalSum -= nums[i];
           

        }

        return cnt;
    }
};
