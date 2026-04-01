class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*if(nums.size()==0){
            return 0;
        }
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[j-1]){
                nums[j]=nums[i];
                j++;
            }
            
        }
        return j;*/
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int i=0;
        for(auto x:s){
            nums[i]=x;
            i++;
        }
        return s.size();
    }
};