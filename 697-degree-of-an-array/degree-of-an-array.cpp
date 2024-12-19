class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_map<int,int> fmp;
        unordered_map<int,int> lmp;

        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            mp[x]++;
            if(fmp.find(x) == fmp.end()) fmp[x] = i;
            lmp[x] = i;
        }

        int maxFreq = INT_MIN;
        for(auto& it : mp)
            if(it.second > maxFreq) maxFreq = it.second;

        int minLength = INT_MAX;
        for(const auto& it : mp){
            if(maxFreq == it.second)
                minLength = min(lmp[it.first] - fmp[it.first] + 1,minLength);
        }

    return minLength;
    }
};