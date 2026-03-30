class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CurrSum=0;
        int MaxSum=INT_MIN;
        for(auto x:nums){
            CurrSum+=x;
            MaxSum = max(CurrSum,MaxSum);
            if(CurrSum<0){
                CurrSum=0;
            }
        }
        return MaxSum;

    }
};