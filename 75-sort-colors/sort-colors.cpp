class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        /*for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }*/

        int low=0;
        int high=n-1;
        int mid=0;
        while(mid <= high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        return;
    }
};