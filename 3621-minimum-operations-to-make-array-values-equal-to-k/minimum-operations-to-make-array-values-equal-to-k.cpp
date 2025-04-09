class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int num : nums){
            if(num>k) mp[num]++;
            else if(num < k) return -1;
        }
    return mp.size();
    }
};