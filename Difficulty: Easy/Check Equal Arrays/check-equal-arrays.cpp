class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        bool ans = true;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                ans=false;
                break;
            }
        }
        return ans;
        
    }
};