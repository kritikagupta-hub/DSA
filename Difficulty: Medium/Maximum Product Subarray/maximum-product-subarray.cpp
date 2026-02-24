class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int max_prod = INT_MIN;  // worst cases me minimum value kya ho sakti hai ?
        int curr_prod = 1;
        for(int i = 0; i< arr.size(); i++){
            if(arr[i] == 0){
                max_prod = max(max_prod, 0);         // if max_prod value is -ve, 0 will be greater     
                curr_prod = 1;
                continue;
            }
            curr_prod = curr_prod * arr[i];
            max_prod = max(max_prod , curr_prod);
        }
        
        curr_prod = 1;
        for(int i = arr.size()-1; i >= 0; i--){
            if(arr[i] == 0){
                max_prod = max(max_prod, 0);
                curr_prod = 1;
                continue;
            }
            curr_prod = curr_prod * arr[i];
            max_prod = max(max_prod , curr_prod);
        }
        return max_prod;
    }
};