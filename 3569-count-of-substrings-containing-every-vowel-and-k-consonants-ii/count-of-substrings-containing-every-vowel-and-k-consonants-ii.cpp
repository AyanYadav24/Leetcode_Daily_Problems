class Solution {
public:
    long long countWithExactK(string s, int k){
        int n = s.size();
        unordered_set<char> v = {'a','e','i','o','u'};
        unordered_map<char,int> mp;
        int i = 0, j = 0, cc = 0;
        long long ans = 0;
        while(j<n){
            if(v.find(s[j]) != v.end()) mp[s[j]]++;
            else cc++;
            while(mp.size() == 5 && cc >= k){
                ans += n-j;
                if(v.find(s[i]) != v.end()){
                    mp[s[i]] == 1 ? mp.erase(s[i]) : mp[s[i]]--;
                }
                else cc--;
                i++;
            }
            j++;
        }
    return ans;
    }
    long long countOfSubstrings(string s, int k) {
        return countWithExactK(s,k) - countWithExactK(s,k+1);
    }
};