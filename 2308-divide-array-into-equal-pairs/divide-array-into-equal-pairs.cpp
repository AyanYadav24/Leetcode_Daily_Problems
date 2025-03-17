class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int,int> mp;
        for(int& i : nums) mp[i]++;
        int s = 0;
        for(auto& it : mp){
            if(it.second % 2 != 0) return false;
        }
    return true;
    }
};