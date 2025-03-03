class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        vector<int> ans;
        int cnt = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == pivot) cnt++;
            else if(nums[i] < pivot) smaller.push_back(nums[i]);
            else larger.push_back(nums[i]);
        }
        copy(smaller.begin(),smaller.end(),back_inserter(ans));
        for(int i=0;i<cnt;i++) ans.push_back(pivot);
        copy(larger.begin(),larger.end(),back_inserter(ans));

    return ans;
    }
};