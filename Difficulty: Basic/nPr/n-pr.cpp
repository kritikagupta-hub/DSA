// User function Template for C++

class Solution {
  public:
    long long nPr(int n, int r) {
        // code here
        return fact(n)/fact(n-r);
    }
    long long fact(int n){
        long long res=1;
        for(int i=2;i<=n;i++){
            res*=i;
        }
        return res;
    } 
};