class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum %2){
            return {};
        }
        vector<long long> ans;
        long long  sum=2;
       

        while(finalSum >= sum){
            ans.push_back(sum);
            finalSum = finalSum-sum;
            sum = sum+2;
        }
        ans.back()+= finalSum;
        return ans;
    }
};