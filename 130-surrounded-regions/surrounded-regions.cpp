class Solution {
public:
    void solve(vector<vector<char>>& board) {
         int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1 || i==0 || j==m-1 || j==0) && board[i][j]=='O'){
                    q.push({i,j});
                    board[i][j] = 'B';
                }
            }
        }
        int rd[4] = {-1,0,1,0};
        int cd[4] = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + rd[i];
                int nc = c + cd[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc] == 'O'){
                    board[nr][nc] = 'B';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'B') board[i][j] ='O';
            }
        }
    }
};