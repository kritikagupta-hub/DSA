class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int low=0,high=0;
        int res=-1;
        map<char,int>f;
        for(high=0;high<s.size();high++){
            f[s[high]]++;//add high
        
            while(f.size()>k){ //adjust window by removing low 
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
            }
            if(f.size()==k){  //if ans obtain return
                res = max(res,high-low+1);
            }
            
        }
        return res;
    }
};