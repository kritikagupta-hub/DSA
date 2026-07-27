class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int count=0;
        int n = nums.size();
        while(j<n){
            if(i==j){
                j++;
                continue;
            }
            if(nums[j]-nums[i]==k){
                count++;
                int left = nums[i];
                int right = nums[j];
                while(i<n && nums[i]== left){
                    i++;
                }
            
                while(j<n && nums[j]== right){
                    j++;
                }
            }
            else if(nums[j]-nums[i] < k){
                j++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};