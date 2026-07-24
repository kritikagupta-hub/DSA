class Solution {
public:
    bool caltime(vector<int>& piles,int h,int speed){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            time += ceil((double)piles[i]/(double)speed);
        }
        if(time<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        /*int maxPile = *max_element(piles.begin(), piles.end());
        for(int speed=1;speed<=maxPile;speed++){
            if (caltime(piles, h, speed)) {
                return speed;
            }
        }*/

        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans =high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(caltime(piles,h,mid)){
                ans=mid;
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};