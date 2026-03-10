class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }  
        int temp=-1;
        for(auto i:mp){
            if(i.second>arr.size()/2){
                if(i.second>temp){
                    temp=i.first;
                }
            }
        }
        return temp;
    }
};