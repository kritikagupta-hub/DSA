class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_ending=nums[0];
        int max_ending=nums[0];
        int res=nums[0];

        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=min_ending*nums[i];
            int v3=max_ending*nums[i];
            max_ending = max(v1,max(v2,v3));
            min_ending = min(v1,min(v2,v3));
            res=max(res,max(max_ending,min_ending));
        }
        return res;
    }
};