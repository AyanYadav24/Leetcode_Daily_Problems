class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        ans[0][0] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if(x == m-1 && y == n-1) return d;

            for(auto& dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n){
                    int max_diff = max(d,abs(heights[x][y]-heights[x_][y_]));
                    if(ans[x_][y_] > max_diff){
                        ans[x_][y_] = max_diff;
                        pq.push({max_diff,{x_,y_}});
                    }
                    
                }
            }
        }
        return ans[m-1][n-1];
    }
};