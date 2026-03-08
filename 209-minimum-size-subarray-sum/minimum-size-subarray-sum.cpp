class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = INT_MAX;
        vector<int>pref(n+1,0);
        for(int i = 0 ; i < n ; i++){
            pref[i+1] = pref[i] + nums[i];
        }

        //use binary search
        for(int i = 0 ; i < n ;i++){
            int need = pref[i] + target; // pref[j] - pref[i] >= target
            int lo = i+1;
            int hi = n;
            int ans = -1;

            while(lo <= hi){
                int mid = (lo + hi)/2;

                if(pref[mid] >= need){
                    ans = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }

            if(ans != -1){
                minlen = min(minlen, ans - i);
            }
        }
        return minlen==INT_MAX ? 0 : minlen;
    }
};