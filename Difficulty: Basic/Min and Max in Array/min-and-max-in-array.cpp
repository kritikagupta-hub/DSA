class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int n =arr.size();
        sort(arr.begin(),arr.end());
        return {arr[0],arr[n-1]};
    }
};