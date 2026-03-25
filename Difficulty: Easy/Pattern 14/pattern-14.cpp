class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i=1;i<=n;i++){
            for(char ch=65;ch<65+i;ch++){
                cout<<ch;
            }
            cout<<endl;
        }
    }
};