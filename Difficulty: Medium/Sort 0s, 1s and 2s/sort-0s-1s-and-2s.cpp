class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int size = arr.size();
        int zeroes = 0;
        int ones = 0;
        
        for(int i = 0; i<size; i++){
            if(arr[i] == 0){
                zeroes++;
            }
            else if(arr[i] == 1){
                ones++;
            }
        }
        for(int i = 0; i<zeroes; i++){
            arr[i] = 0;
        }
        for(int i = zeroes; i<zeroes+ones; i++){
            arr[i] = 1;
        }
        for(int i = zeroes+ones; i<size; i++){
            arr[i] = 2;
        }
    }
};