class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        int n= arr.size();
        check(arr,0,n);
        
    }
    bool check(vector<int>& arr,int i, int n){
        if(i==n || i==n-1){
            return true;
        }
        if(arr[i]>arr[i+1]){
            return false;
        }
        return check(arr, i+1, n);
    }
};