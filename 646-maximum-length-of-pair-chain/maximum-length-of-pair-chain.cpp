class Solution {
public:
    int solve(vector<vector<int>>&pairs, int n, int i, int prev, vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int nottake= solve(pairs,n,i+1,prev,dp);
        if(prev==-1 || pairs[prev][1]<pairs[i][0]){
            int take=1+solve(pairs,n,i+1,i,dp);
            return dp[i][prev+1] =max(take,nottake);
        }
        return dp[i][prev+1]= nottake;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(pairs.begin(),pairs.end());
        return solve(pairs,n,0,-1,dp);
    }
};