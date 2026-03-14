class Solution {
public:

    // Function to check if placing queen at (row,col) is safe
    bool isSafe(int row, int col, vector<string> &board, int n) {

        int x = row;
        int y = col;

        // Check left side in the same row
        while(y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            y--;
        }

        x = row;
        y = col;

        // Check upper left diagonal
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        x = row;
        y = col;

        // Check lower left diagonal
        while(x < n && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        // If no queen found in attacking position
        return true;
    }

    // Backtracking function
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {

        // Base case: if all columns are filled
        if(col == n) {
            ans.push_back(board); // store solution
            return;
        }

        // Try placing queen in every row of current column
        for(int row = 0; row < n; row++) {

            // Check if it is safe to place queen
            if(isSafe(row, col, board, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Recursive call for next column
                solve(col + 1, board, ans, n);

                // Backtracking: remove queen
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Create empty board
        vector<string> board(n, string(n, '.'));

        // Start solving from column 0
        solve(0, board, ans, n);

        return ans;
    }
};