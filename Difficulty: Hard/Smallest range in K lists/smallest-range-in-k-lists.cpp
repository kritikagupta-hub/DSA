class Node{
    public:
    int data;
    int row;
    int column;
    
    Node(int d,int r,int c){
        data = d;
        row = r;
        column = c;
    }
};
class compare{
    public:
    bool operator()(Node*a,Node* b){
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        int x = mat.size();
        int y = mat[0].size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        priority_queue<Node*,vector<Node*>,compare> minHeap;
        for(int i = 0;i<mat.size();i++){
           mini = min(mini,mat[i][0]);
           maxi = max(maxi,mat[i][0]);
           minHeap.push(new Node(mat[i][0],i,0));
        }
        int fin = (maxi-mini+1);
        int start = mini; int end = maxi;
        int r = mini; int s = maxi;
        while(!minHeap.empty()){
            Node* temp = minHeap.top();
            minHeap.pop();
            int t = fin;
            fin = min(fin,abs(temp->data-end)+1);
            if(fin != t){
                r = temp->data;
                s = end;
            }
            if(temp->column < y-1){
                int d = temp->column;
                int c = temp->row;
                minHeap.push(new Node(mat[c][d+1],c,d+1));
                end = max(end,mat[c][d+1]);
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(r);
        ans.push_back(s);
        return ans;
    }
};