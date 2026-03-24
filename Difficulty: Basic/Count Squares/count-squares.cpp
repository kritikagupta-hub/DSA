class Solution {
  public:
    int countSquares(int n) {
        // code here
        int c=0;
        for(int i=1;i*i<n;i++){
            c++;
        }
        return c;
    }
};