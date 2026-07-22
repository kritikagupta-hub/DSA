class Solution {
public:

    bool CalDays(vector<int>& weights, int days, int capacity) {
        
        int hold = 0;
        int noOfDays = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (hold + weights[i] <= capacity) {
                hold += weights[i];
            }
            else {
                noOfDays++;
                hold = weights[i];
            }
        }
        if (noOfDays <= days) {
            return true;
        }
        else {
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(CalDays(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};