class Solution {
public:
    // Helper function:
    // x = remaining '(' to place
    // y = remaining ')' to place
    // s = current built string
    // answer = vector holding all valid combinations
    void func(int x, vector<string>& answer, int y, string s) {
        // If no ')' are left, the string is complete and valid
        if (y == 0)
            answer.push_back(s);
        // If we still have '(' available, we can add one and recurse
        else if (x > 0) 
            func(x - 1, answer, y, s + '(');
        
        // If we have ')' left AND we have used more '(' than ')'
        // so far (x < y), we can safely add a ')'
        if (y > 0 && x < y) 
            func(x, answer, y - 1, s + ')');
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> answer;          // stores all valid combinations
        func(n, answer, n, "");         // start with n '(' and n ')' remaining
        return answer;                  // return collected results
    }
};