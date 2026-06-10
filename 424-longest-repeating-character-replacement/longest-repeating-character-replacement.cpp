class Solution {
public:
    int findMax(vector<int> &f){
        int m=0;
        for(int i =0;i<256;i++){
            m= max(m,f[i]);
        }
        return m;
    }
    int characterReplacement(string s, int k) {
        int low=0;
        int high=0;
        int res=INT_MIN;

        vector<int> f(256,0);

        for(int high=0;high<s.size();high++){// add high in window
            f[s[high]]++;

            int len = high-low+1;
            int max_cnt = findMax(f);

            int diff = len - max_cnt;

            while(diff>k){//shrink
                f[s[low]]--;
                low++;
                max_cnt = findMax(f);

                len =high-low+1;
                diff = len-max_cnt;

            } 
            // k==diff or k<diff then just cal ans
            len = high-low+1;
            res= max(res,len);
        }
        return res;
    }
};