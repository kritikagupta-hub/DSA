class Solution {
  public:
    void printTriangle(int n) {
        
        int i = 1;
        while(i <= n) {
            int j = 1;
            while(j <= i) {
                cout << "* ";
                j++;
            }
            cout << endl;
            i++;
        }

        i = n - 1;

        while(i >= 1) {
            int j = 1;
            while(j <= i) {
                cout << "* ";
                j++;   
            }
            cout << endl;
            i--;
        }
    }    
};