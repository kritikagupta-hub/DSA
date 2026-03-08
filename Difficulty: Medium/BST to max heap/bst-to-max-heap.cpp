// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
public:
    void solve(Node* root,vector<int> &v,int &i){
        if(root == NULL){
            return ;
        }
        solve(root->left,v,i);
        v.push_back(root->data);
        solve(root->right,v,i);
        root->data = v[i++];
        return ;
    }
    void convertToMaxHeapUtil(Node* root) {
       vector<int> v;
       int i = 0;
       solve(root,v,i);
    }
};