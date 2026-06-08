class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum=0;
        int low=0;
        int high=k-1;
        int res=INT_MIN;
        for(int i=low;i<=high;i++){
            sum += arr[i];
        }    
        while(high<arr.size()){
            res=max(res,sum);
            high++;
            if(high==arr.size()){
                break;
            }
            sum=sum-arr[low];
            low++;
            sum=sum+arr[high];
        }
        return res;
    }
};