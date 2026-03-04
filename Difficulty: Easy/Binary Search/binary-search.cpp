class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int low=0, high=n-1;
        int ans=-1;
        while(high>=low){
            int mid=(high+low)/2;
            if(arr[mid]==k){
                ans=mid;
                high = mid - 1;
            }
            else if(k>arr[mid])
            low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};