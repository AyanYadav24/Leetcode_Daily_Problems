class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        int i=0;
        while(i<n){
            int p = nums[i];
            while(i < n-1 && nums[i] + 1 == nums[i+1]) i++;
            cout << p << " " << nums[i] << endl;
            string s = "";
            if(p==nums[i]) s = to_string(p);
            else s = to_string(p) + "->" + to_string(nums[i]);
            ans.push_back(s);
            i++;
        }
    return ans;
    }
};