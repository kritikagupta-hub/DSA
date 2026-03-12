class Solution {
public:
    int maxFrequency(int arr[], int n, int k) {
        
        vector<int> a(arr, arr + n);
        sort(a.begin(), a.end());
        
        long long sum = 0;
        int l = 0, ans = 1;
        
        for(int r = 0; r < n; r++){
            sum += a[r];
            
            while((long long)a[r] * (r - l + 1) - sum > k){
                sum -= a[l];
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};