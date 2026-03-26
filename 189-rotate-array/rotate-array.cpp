class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        //reverse whole array
        reverse(nums.begin(),nums.end());
        //reverse k element k=3
        reverse(nums.begin(),nums.begin()+k);
        //reverse remaining 
        reverse(nums.begin()+k,nums.end());
    }
};