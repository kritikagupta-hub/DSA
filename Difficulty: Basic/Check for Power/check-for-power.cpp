class Solution {
  public:
    int isPowerOfAnother(int X, int Y) {
        // code here
        if(X==1){
            return (Y==1);
        }
        int i=1;
        while(i<Y){
            i*=X;
        }
        return(i==Y);
    }
};