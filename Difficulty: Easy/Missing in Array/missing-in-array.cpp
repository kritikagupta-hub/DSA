class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n=arr.size();
       sort(arr.begin(),arr.end());
       
       int count=1;
       for(int i=0;i<arr.size();i++){
           if(arr[i]==count){
               count++;
           }else{
               break;
           }
                         
       }
      
      return count;
        
    }
};