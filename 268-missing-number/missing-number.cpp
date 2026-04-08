class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int n = nums.size();
        for(int i=1;i<=n;i++){
            if(m.find(i) == m.end()){
                return i;
            }
        }
        return 0;*/
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;
        for(int i=1;i<=n;i++){
            xor1^=i;
        }
        for(int x:nums){
            xor2^=x;
        }
        return xor1^xor2;
    }
};