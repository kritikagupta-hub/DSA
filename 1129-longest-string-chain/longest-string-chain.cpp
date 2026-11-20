class Solution {
public:
    int LIS(vector<string> &words,int n, int i, int prev,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int nottake=LIS(words,n,i+1,prev,dp);
        if(prev==-1 || check(words[prev],words[i])){
            int take= 1+LIS(words,n,i+1,i,dp);
            return dp[i][prev+1]=max(take,nottake);
        }
        return dp[i][prev+1] = LIS(words,n,i+1,prev,dp);
    }
    bool check(string &a, string &b){
        if(b.size()!=a.size()+1){  //check b ki length a se exactly 1 >
            return false; 
        }
        int first=0;
        int second =0;
        while(first<a.size() && second<b.size()){
            if(a[first]==b[second]){
                first++;
                second++;
            }
            else{
                second++;
            }
        }
        return first== a.size();
    }

    static bool campare(string a, string b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),campare);
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(words,n,0,-1,dp);
    }
};