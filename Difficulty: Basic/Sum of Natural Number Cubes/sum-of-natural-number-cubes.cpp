// User function template for C++

class Solution {
  public:
    int sumOfSeries(int n) {
        // code here
        int c=0;
        for(int i=1;i<=n;i++){
            int a=i*i*i;
            c+=a;
        }
        return c;
        
        
    }
};