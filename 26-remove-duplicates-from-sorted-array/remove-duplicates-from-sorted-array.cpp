class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        //first unique elemnt in j 
        int j=1;
        for(int i=1;i<nums.size();i++){
            //as we know that array is sorted so same elemnt are at adjacent we will check
            //if j-1!=i then put it into unique list;
            if(nums[i]!=nums[j-1]){
                nums[j]=nums[i];
                j++;
            }
            
        }
        return j;
    }
};