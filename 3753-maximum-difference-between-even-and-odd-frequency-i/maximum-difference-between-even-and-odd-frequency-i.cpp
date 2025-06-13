class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto& ch : s)   mp[ch]++;
        int ev = INT_MIN, od = INT_MIN, evm = INT_MAX, odm = INT_MAX;
        for(auto it : mp){
            if(it.second % 2 == 0 ){ ev = max(ev,it.second); evm = min(evm,it.second); }
            else { od = max(od,it.second); odm = min(odm,it.second); }
        }
        int ans = max(od - evm , odm - ev);
        return ans;
    }
};