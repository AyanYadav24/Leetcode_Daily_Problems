class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }
        for(auto it : mp){
            ans += (it.second * (it.second - 1) / 2) * 8;
        }
    return ans;
    }
};