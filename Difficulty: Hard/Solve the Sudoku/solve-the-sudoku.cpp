class Solution {
public:

    int row[9][10] = {0};
    int col[9][10] = {0};
    int box[9][10] = {0};

    bool solve(vector<vector<int>> &board){

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){

                if(board[r][c] == 0){

                    for(int val = 1; val <= 9; val++){

                        int b = (r/3)*3 + (c/3);

                        // check in O(1)
                        if(row[r][val] == 0 && col[c][val] == 0 && box[b][val] == 0){

                            board[r][c] = val;

                            row[r][val] = 1;
                            col[c][val] = 1;
                            box[b][val] = 1;

                            if(solve(board))
                                return true;

                            // backtrack
                            board[r][c] = 0;
                            row[r][val] = 0;
                            col[c][val] = 0;
                            box[b][val] = 0;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<int>> &mat) {

        // initialize hash arrays
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){

                if(mat[r][c] != 0){

                    int val = mat[r][c];
                    int b = (r/3)*3 + (c/3);

                    row[r][val] = 1;
                    col[c][val] = 1;
                    box[b][val] = 1;
                }
            }
        }

        solve(mat);
    }
};