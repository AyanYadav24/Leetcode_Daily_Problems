class Solution {
private:
    bool isSafe(int row, int col, vector<string> board, int n){
        for(int i=0;i<n;i++){
            if(board[row][i] == 'Q') return false;
            if(board[i][col] == 'Q') return false;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j == row+col) && board[i][j] == 'Q') return false;
                if((i-j == row-col) && board[i][j] == 'Q') return false;
            }
        }
    return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);

        solve(0,board,ans,n);
        return ans;

    }
};