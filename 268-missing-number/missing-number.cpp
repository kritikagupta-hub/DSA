class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int n = nums.size();
        for(int i=1;i<=n;i++){
            if(m.find(i) == m.end()){
                return i;
            }
        }
        return 0;
    }
};