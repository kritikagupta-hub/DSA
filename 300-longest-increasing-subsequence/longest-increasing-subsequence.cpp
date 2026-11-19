class Solution {
public:
    int solve(vector<int>&nums, int n,int i,int prev,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int nottake = solve(nums,n,i+1,prev,dp);
        if(prev==-1 || nums[i] > nums[prev]){
            int take=1+solve(nums,n,i+1,i,dp);
            return dp[i][prev+1]=max(take,nottake);
        }
        return dp[i][prev+1]=solve(nums,n,i+1,prev,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,n,0,-1,dp);
    }

};