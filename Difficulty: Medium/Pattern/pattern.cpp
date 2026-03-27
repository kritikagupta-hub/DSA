class Solution {
  public:
    void printDiamond(int n) {
        // code here
       int i=0;
       while(i<n){
           int j=1;
           while(j<=n-i){
               cout<<" ";
               j++;
           }
           j=0;
           while(j<=i){
               cout<<"* ";
               j++;
           }
           cout<<endl;
           i++;
       
       }
        i = n;

        while(i >= 1) {
            int j = 1;

            while(j <= n - i) {
                cout << " ";
                j++;
            }

            j = 1;

            while(j <= i) {
                cout << " *";
                j++;
            }

            cout << endl;
            i--;
        }
    }
};