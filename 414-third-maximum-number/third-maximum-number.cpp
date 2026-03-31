class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        /*nums.erase(unique(nums.begin(),nums.end()),nums.end()); 
        int n=nums.size();
        if(n>=3){
            return nums[n-3];
        }
        else{
            return nums[n-1];
        } */
        int count=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] != nums[i+1]){
                count++;
            }
            if(count==3){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};