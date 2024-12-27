class Solution {
public:
    bool isValid(char ch, int row, int col, vector<vector<char>> board){
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i] == ch) return false;
            if(i!=row && board[i][col] == ch) return false;
            int r = 3*(row/3) + i/3;
            int c = 3*(col/3) + i%3;
            if(r!=row && c!=col && board[r][c] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch = board[i][j];
                if(ch != '.'){
                    if(isValid(ch,i,j,board) == false)
                        return false; 
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};