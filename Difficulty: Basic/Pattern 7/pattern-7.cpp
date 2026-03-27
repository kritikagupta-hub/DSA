class Solution {
  public:
    void printTriangle(int n) {
        // code here
        /*int i=0;
        for(i=0;i<n;i++){
            for(int j=0;j<(n-i)-1;j++){
                cout<<" ";
            }
            for(int j=0;j<(2*i)+1;j++){
                cout<<"*";
            }
            cout<<endl;
        }*/
        int i=0;
        while(i<n){
            int j=0;
            while(j<(n-i)-1){
                cout<<" ";
                j++;
            }
            j=0;
            while(j<(2*i)+1){
                cout<<"*";
                j++;
            }
            cout<<endl;
            i++;
        }
    }
};

