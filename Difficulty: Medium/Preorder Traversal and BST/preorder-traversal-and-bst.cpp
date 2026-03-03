// User function Template for C++

class Solution {
  public:
  int index = 0;
  void bst(int arr[] , int N , int lower , int maxi){
      if(index == N || arr[index] <= lower || arr[index] >= maxi){
          return ;
      }
      
      int value = arr[index];
      index++;
      bst(arr , N , lower , value);
      bst(arr , N , value , maxi);
  }
    int canRepresentBST(int arr[], int N) {
       bst(arr , N , INT_MIN, INT_MAX);
       if(index == N) return 1;
       return 0;
    }
};