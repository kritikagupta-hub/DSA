class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int onedelete=arr[0];
        int nodelete=arr[0];
        int res=arr[0];
        for(int i=1;i<n;i++){
            onedelete = max(onedelete+arr[i],nodelete);
            nodelete = max(arr[i],nodelete+arr[i]);
            res=max(res, max(onedelete,nodelete));
        }
        return res;
    }
};