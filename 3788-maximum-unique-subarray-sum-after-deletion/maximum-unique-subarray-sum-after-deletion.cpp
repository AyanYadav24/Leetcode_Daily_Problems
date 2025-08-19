class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int max_sum = *max_element(nums.begin(),nums.end()), curr_sum = 0;
        for(int num : nums){
            if((st.find(num) != st.end()) || num < 0) { curr_sum += 0; }
            else {
                curr_sum += num;
                max_sum = max(max_sum , curr_sum);
            }
            st.insert(num);
        }
        return max_sum;
    }
};