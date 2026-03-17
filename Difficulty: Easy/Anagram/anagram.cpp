class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here in c++
        
        int arr1[26] ={0};
        int arr2[26] ={0};
        for(int i=0 ;  i< s1.length() ; i++){
            arr1[s1[i] - 'a'] ++;
            
        }
        for(int i=0 ;  i< s2.length() ; i++){
            arr2[s2[i] - 'a'] ++;
        }
        for(int i=0; i< 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
};