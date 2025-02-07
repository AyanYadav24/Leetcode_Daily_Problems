class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<int> ans;

        for(auto it : queries){
            int ball = it[0];
            int color = it[1];

            if(mp1.find(ball) != mp1.end()){
                int pcob = mp1[ball];
                mp2[pcob] == 1 ? mp2.erase(pcob) : mp2[pcob]--;
            }

            mp1[ball] = color;
            mp2[color]++;
            ans.push_back(mp2.size());
        }
        return ans;
    }
};