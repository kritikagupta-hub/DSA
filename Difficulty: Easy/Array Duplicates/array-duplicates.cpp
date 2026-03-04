class Solution {
  public:
   vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        vector<int> result;
        
        for(auto x : arr) {
            mp[x]++;
        }
        
        for(auto x : mp) {
            if(x.second > 1) {
                result.push_back(x.first);
            }
        }
        return result;
    }
};