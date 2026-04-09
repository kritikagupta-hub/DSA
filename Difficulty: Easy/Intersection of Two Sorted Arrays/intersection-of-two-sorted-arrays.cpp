class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> s(a.begin(),a.end());
        vector<int> res;
        for(auto x:b){
            if(s.count(x)){
                res.push_back(x);
                s.erase(x);
            }
        }
        return res;
    }
};