class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right=n-1;

            //target sum   nums[i]+nums[left]+nums[right] = 0
            //nums[left] = nums[right] = -1*nums[i]

            int sum = -1*nums[i];
            while(left<right){
                int s =  nums[left]+nums[right];
                if(s==sum){

                    // correct triplet
                    res.push_back({nums[i],nums[left],nums[right]}) ;
                    left++;
                    right--;
                
                    // skip duplicates from left
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }
                    // skip duplicate from right
                    while(left<right && nums[right]==nums[right+1]){
                        right--;
                    }
                }

                //if s is smaller
                else if(s<sum){
                    left++;
                }

                //if larger sum
                else{
                    right--;
                }
            }
        }
        return res;

    }
};