class Solution {
public:

    bool isSafe(int newx, int newy, vector<vector<int>>& maze, vector<vector<bool>>& visited, int n){
        if(newx >= 0 && newx < n && newy >= 0 && newy < n && visited[newx][newy] == 0 && maze[newx][newy] == 1){
            return true;
        }
        return false;
    }

    void solve(int x, int y, vector<vector<int>>& maze, int n, vector<string>& ans, vector<vector<bool>>& visited, string path){

        // base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        if(isSafe(x+1, y, maze, visited, n)){
            solve(x+1, y, maze, n, ans, visited, path + 'D');
        }

        // Left
        if(isSafe(x, y-1, maze, visited, n)){
            solve(x, y-1, maze, n, ans, visited, path + 'L');
        }

        // Right
        if(isSafe(x, y+1, maze, visited, n)){
            solve(x, y+1, maze, n, ans, visited, path + 'R');
        }

        // Up
        if(isSafe(x-1, y, maze, visited, n)){
            solve(x-1, y, maze, n, ans, visited, path + 'U');
        }

        visited[x][y] = 0; // backtracking
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();
        vector<string> ans;

        if(maze[0][0] == 0)
            return ans;

        vector<vector<bool>> visited(n, vector<bool>(n, 0));

        string path = "";

        solve(0, 0, maze, n, ans, visited, path);

        return ans;
    }
};