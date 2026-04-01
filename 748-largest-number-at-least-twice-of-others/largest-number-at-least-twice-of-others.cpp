class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int idx=-1;

        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max=nums[i];
                idx=i;
            }
        }
        for(int i=0;i<n;i++){
            if(max == nums[i]){
                continue;
            }
            if(max < 2*nums[i]){
                return -1;
            }
        }
        return idx;

    }
};