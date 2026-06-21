class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int best_ending=a[0];
        int ans=a[0];
        for(int i=1;i<a.size();i++){
            int v1= best_ending+a[i];
            int v2= a[i];
            best_ending = min(v1,v2);
            ans= min(ans,best_ending);
            
        }
        return ans;
    }
};
