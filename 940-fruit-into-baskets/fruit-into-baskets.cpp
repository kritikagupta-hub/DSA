class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int high=0;
        int res=0;
        int k=2;
        map<int,int> f;
        for(int high=0;high<fruits.size();high++){
            f[fruits[high]]++; // add high

            //window  adjustment by shriking low and remove freq 0 from map
            while(f.size()>k){
                f[fruits[low]]--;
                if(f[fruits[low]]==0){
                    f.erase(fruits[low]);
                }
                low++;
            }

            // ans found then cal len
            int len = high-low+1;
            res=max(res,len);
        }
        return res;

    }
};