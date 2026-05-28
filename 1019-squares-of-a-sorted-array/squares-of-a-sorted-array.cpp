class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        for(int i=0;i<nums.size();i++){     //saparate neg and pos no.
            if(nums[i]>=0){   //if pos no.
                pos.push_back(nums[i]);
            }
            else{ // if neg no.
                neg.push_back(nums[i]);
            }
        }
        
        //if all no. are pos
        if(neg.size()==0){
            for(int i=0;i<pos.size();i++){
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }

        // if all no. are negative
        if(pos.size() == 0){
            for(int i=0;i<neg.size();i++){
                neg[i]=neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }

        int i=0;//point in neg array first element 
        int j=0;// point in pos array first elemnt 
        int idx=0;
        int n=neg.size();
        int m=pos.size();
        vector<int> res(n+m);
        for(int i=0;i<n;i++){
            neg[i]=neg[i]*neg[i];
        }
        reverse(neg.begin(),neg.end());
        for(int i=0;i<m;i++){
            pos[i]=pos[i]*pos[i];
        }

        //merge if both are true
        while(i<n && j<m){
            if(neg[i] <= pos[j]){
                res[idx]=neg[i];
                idx++;
                i++;
            }
            else{
                res[idx]=pos[j];
                idx++;
                j++;
            }
        }

        while(j<m){   //if j is true pos
            res[idx]=pos[j];
            idx++;
            j++;
        }
        while(i<n){   // if i is true neg
            res[idx]=neg[i];
            idx++;
            i++;
        }
        return res;
    }
};