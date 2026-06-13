class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        int res=INT_MIN;
        int Zeros=0;
        for(high=0;high<nums.size();high++){

            if(nums[high]==0){
                Zeros++;
            }
            
            while(Zeros>k){
                if(nums[low]==0){
                    Zeros--;
                }
                low++;
            }

            res=max(res,high-low+1);
        }
        return res;
    }
};