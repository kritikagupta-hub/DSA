class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        /*unordered_set<int>s;
        for(int i=0;i<a.size();i++)
        {
            s.insert(a[i]);
        }
        for(int i=0;i<b.size();i++){
            if(s.find(b[i])== s.end()){
                return false;
            }
        }
        return true;*/
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                i++;
            }
            else{
                return false;
            }
        }
        return(j==b.size());
        
    }
};