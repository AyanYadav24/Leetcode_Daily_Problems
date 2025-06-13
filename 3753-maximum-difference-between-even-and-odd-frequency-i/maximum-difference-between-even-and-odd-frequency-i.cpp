class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto& ch : s)   mp[ch]++;
        int od = INT_MIN, evm = INT_MAX;
        for(auto it : mp){
            if(it.second % 2 == 0 ){ evm = min(evm,it.second); }
            else { od = max(od,it.second); }
        }
        return od - evm;
    }
};