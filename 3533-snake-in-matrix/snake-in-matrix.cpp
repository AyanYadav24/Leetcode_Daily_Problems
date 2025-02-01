class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        unordered_map<string,pair<int,int>> mp;
        mp["RIGHT"] = {0,1};
        mp["DOWN"]  = {1,0};
        mp["UP"]    = {-1,0};
        mp["LEFT"]  = {0,-1};

        int i=0,j=0;
        for(auto& str : commands){
            i+=mp[str].first;
            j+=mp[str].second;
        }
        return i*n + j;
    }
};