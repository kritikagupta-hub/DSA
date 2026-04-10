class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        if(n < 3)       return {};
        vector<int> right(n);
        right[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = max(arr[i], right[i+1]);
        }
        int left = arr[0];
        for(int i=1; i<n-1; i++){
            if(left<arr[i] && arr[i]<right[i+1])
                return{left, arr[i], right[i+1]};
            left = min(left, arr[i]);
        }
        return {};
    }
};