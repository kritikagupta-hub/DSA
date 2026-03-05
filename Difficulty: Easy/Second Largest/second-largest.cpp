class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = arr[0];
        int n = arr.size();
        int secondlargest = -1;
        for(int i=1; i<n; i++){
            if(largest < arr[i]){
                secondlargest = largest;
                largest = arr[i];
            }
            if(secondlargest < arr[i] && arr[i]<largest){
                secondlargest = arr[i];
            }
            
        }
        
        return secondlargest;
    }
};