class Solution {
public:

    double solve(double x, long long n) {
        if(n == 0)
            return 1;
        double h = solve(x, n/2);
        if(n % 2 == 0){
            return h * h;
        }
        else{
            return x * h * h;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        return solve(x, N);
    }
};