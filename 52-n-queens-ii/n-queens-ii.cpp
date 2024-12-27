class Solution {
public:
    bool isValid(int row, int col, vector<string> board, int n){
        for(int i=0;i<n;i++){
            if(board[row][i] == 'Q') return false; // col
            for(int j=0;j<n;j++){
                if((i+j == row+col) && board[i][j] == 'Q') return false; // diagonal - 1
                if((i-j == row-col) && board[i][j] == 'Q') return false; // diagonal - 2
            }
        }
    return true;
    }
    void solve(int col, int& cnt, vector<string>& board, int n){
        if(col == n){
            cnt++;
            return;
        }

        for(int row = 0; row < n; row++){
            if(isValid(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,cnt,board,n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int cnt = 0;
        string s(n,'.');
        vector<string> board(n,s);
        solve(0,cnt,board,n);
        return cnt;
    }
};