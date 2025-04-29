class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int s = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            int rem = (s)%k;
            if(rem<0){
                rem+=k;
            }
            ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};