

class Solution {
  public:
     vector<int> leaders(vector<int>& arr) {
        vector<int>v;
       int n=arr.size();
       int maxi=arr[n-1];
       for(int i=n-1;i>=0;i--)
       {
          if(arr[i]>=maxi)
          {
              v.push_back(arr[i]);
              maxi=arr[i];
          }
       }
          reverse(v.begin(), v.end());
          return v;
    }
};