class Solution {
private:
    bool isSafe(int row, int col, vector<string> board, int n){
        int rowdup = row;
        int coldup = col;

        //left up-diagonal
        while(row >=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;col--;
        }
        row = rowdup;
        col = coldup;

        //down right-diagonal
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;col--;
        }
        row = rowdup;
        col = coldup;

        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
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