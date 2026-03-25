class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int even_min=INT_MAX;
       int odd_min=INT_MAX;
       bool has_even=false;
       bool has_odd=false;


        for(auto a : nums1){
            if(a % 2==0){
               has_even=true;
               even_min=min(even_min,a);
            }
            else{
               has_odd=true;
               odd_min=min(odd_min,a);
            }
        }
        if(!has_even ||!has_odd)
            return true;
            return odd_min < even_min;

    }
};
        