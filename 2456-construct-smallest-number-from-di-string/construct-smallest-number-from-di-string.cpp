class Solution {
public:
    bool solve(int index, string patt, string& res, string& curr, vector<int>& vis){
        if(curr.size() == patt.size() + 1){
            res = curr;
            return true;
        }

        for(char d = '1'; d <= '9'; d++){
            if(vis[d - '0']) continue;
            if(!curr.empty() && ((patt[index-1] == 'I' && curr.back() >= d) || (patt[index-1] == 'D' && curr.back() <= d))) continue;
            vis[d - '0'] = 1;
            curr.push_back(d);
            if(solve(index+1, patt, res, curr, vis)) return true;
            vis[d - '0'] = 0;
            curr.pop_back(); 
        }
        return false;
    }

    string smallestNumber(string patt) {
        vector<int> vis(10, 0);
        string res = "";
        string curr = "";
        solve(0, patt, res, curr, vis);
        return res;
    }
};
