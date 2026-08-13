
class Solution {
  public:
    int countWays(int n) {
        // your code here
        return solve(n);
        
    }
    int solve(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return solve(n - 1) + solve(n - 2) + solve(n - 3);
    }
    
};
