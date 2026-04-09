class Solution {
public:
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    };
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        for(auto i:mp){
            if(isPrime(i.second)){
                return true;
            }
        }
        return false;
    }
};