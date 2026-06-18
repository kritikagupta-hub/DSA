class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size();i++){
            for(int j=i;j>0;j--){
                if(arr[j]<arr[j-1]){
                    swap(arr[j],arr[j-1]);
                }
                else{
                    break;
                }
            }
        }
    }
};