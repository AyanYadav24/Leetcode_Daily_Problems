class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //sort(begin(nums),end(nums));
        for(int num : nums)
        if(num < k) return -1;
        
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int num : nums){
            if(num>k) mp[num]++;
        }
    return mp.size();
    }
};