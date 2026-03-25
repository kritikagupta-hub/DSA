class Solution {
  public:
    bool isPalindrome(int n) {
        // code here.
        int rev=0;
        int temp=n;
        while(temp!=0){
            int dig=temp%10;
            rev=rev*10+dig;
            temp=temp/10;
        }
        return rev==n;
    }
};