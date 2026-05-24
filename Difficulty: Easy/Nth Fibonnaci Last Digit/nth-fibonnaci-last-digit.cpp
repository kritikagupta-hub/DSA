class Solution {
public:

    int fiboo(int n, vector<int> &dp) {

        if(n <= 1) {
            return n;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        dp[n] = (fiboo(n-1, dp) + fiboo(n-2, dp)) % 10;

        return dp[n];
    }

    int fib(int n) {

        vector<int> dp(n + 1, -1);

        return fiboo(n, dp);
    }
};