class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int res=1;//1 unique element is always there 
        while(j<nums.size()){
            if(nums[j]==nums[j-1]){
                j++;
                continue;
            }
            else{
                //unique element milaa
                nums[i+1]=nums[j];
                i++;
                res++;
                j++;
            }
        }
        return res;
    }
};