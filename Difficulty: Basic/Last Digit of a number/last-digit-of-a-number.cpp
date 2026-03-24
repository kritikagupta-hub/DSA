class Solution {
  public:
    int lastDigit(int n) {
        // Code here
        n=n%10;
        if(n<0){
            n=-n;
        }
        return n;
    }
};