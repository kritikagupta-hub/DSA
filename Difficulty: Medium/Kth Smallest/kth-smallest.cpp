class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int size = arr.size();
        priority_queue<int> pq;
        for(int i=0;i<size;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        int ans = pq.top();
        // while(!pq.empty()){
         //   int current_elemnt = pq.top();
          //  cout<<current_element<<" " ;
           // pq.pop();
           // cout<<endl;
        //}
        return ans;
    }
};