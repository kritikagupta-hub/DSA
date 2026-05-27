class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(n+m);
        int idx=0;
        int i=0,j=0;
        // only true if both are true 
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                res[idx] = nums1[i];
                idx++;
                i++;
            }
            else{
                res[idx] = nums2[j];
                idx++;
                j++;
            }
        }

    // if one fails so handle each cases individually
        while(j<n){
            res[idx] = nums2[j];
            idx++;
            j++;
        }
        while(i<m){
            res[idx] = nums1[i];
            idx++;
            i++;
        }
        //copy to nums1
        for(int k=0;k<m+n;k++){
            nums1[k]=res[k];
        }
    }
};