class Solution {
    int solve(vector<int>& nums, int i, int sum, int target, vector<vector<int>>& dp){
        if(i==nums.size()){
            if(sum==target) return 1;
            return 0;
        }
        int idx = sum + 1000;
        if(dp[i][idx] != -1) return dp[i][idx];
        int plus = solve(nums, i+1, sum + nums[i], target, dp);
        int minus = solve(nums, i+1, sum - nums[i], target, dp);
        return dp[i][idx] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2000, -1));
        return solve(nums, 0, 0, target, dp);
    }
};