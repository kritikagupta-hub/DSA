class Solution{
public:

    // Function to check whether placing queen is safe
    bool isSafe(int row, int col, vector<int> &board){
        
        // check all previously placed queens
        for(int prevCol = 0; prevCol < col; prevCol++){
            
            int prevRow = board[prevCol];

            // same row check
            if(prevRow == row)
                return false;

            // diagonal check
            if(abs(prevRow - row) == abs(prevCol - col))
                return false;
        }

        return true;
    }

    // Backtracking function
    void solve(int col, int n, vector<int> &board, vector<vector<int>> &ans){

        // base case: all queens placed
        if(col == n){
            
            vector<int> temp;
            
            // convert to 1-based indexing (GFG requirement)
            for(int i = 0; i < n; i++)
                temp.push_back(board[i] + 1);

            ans.push_back(temp);
            return;
        }

        // try placing queen in every row
        for(int row = 0; row < n; row++){

            if(isSafe(row, col, board)){

                board[col] = row;  // place queen

                solve(col + 1, n, board, ans);

                // backtracking
                board[col] = -1;
            }
        }
    }

    vector<vector<int>> nQueen(int n){

        vector<vector<int>> ans;

        vector<int> board(n, -1); // board[col] = row

        solve(0, n, board, ans);

        return ans;
    }
};