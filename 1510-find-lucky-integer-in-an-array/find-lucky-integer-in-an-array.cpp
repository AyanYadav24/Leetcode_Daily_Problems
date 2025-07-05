class Solution {
public:
    int findLucky(vector<int>& arr) {
       map<int,int> mp;
       int ans = -1;
       for(int num : arr){
        mp[num]++;
       } 
       for(auto it : mp){
        if(it.first == it.second) ans = it.first;
       }
    return ans;
    }
};