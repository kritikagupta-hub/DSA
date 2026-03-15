class Solution {
public:

    bool isSafe(int row, int col, vector<vector<char>>& board){

        char val = board[row][col];

        for(int i = 0; i < 9; i++){

            // row check
            if(i != col && board[row][i] == val)
                return false;

            // column check
            if(i != row && board[i][col] == val)
                return false;

            // 3x3 box check
            int r = 3*(row/3) + i/3;
            int c = 3*(col/3) + i%3;

            if((r != row || c != col) && board[r][c] == val)
                return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){

                if(board[row][col] != '.'){

                    if(!isSafe(row, col, board))
                        return false;
                }
            }
        }

        return true;
    }
};