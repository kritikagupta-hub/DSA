/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> ans;
        Node* curr1=root1;
        Node* curr2=root2;
        
        stack<Node*> st1;
        stack<Node*> st2;
        
        while(curr1 || curr2 || !st1.empty() || !st2.empty()){
            while(curr1){
                st1.push(curr1);
                curr1=curr1->left;
            }
            
            while(curr2){
                st2.push(curr2);
                curr2=curr2->left;
            }
            
            int v1 = (st1.empty()? INT_MAX: st1.top()->data);
            int v2 = (st2.empty()? INT_MAX: st2.top()->data);
            if(v1<v2){
                curr1=st1.top();
                st1.pop();
                ans.push_back(v1);
                curr1=curr1->right;
            }else if(v1>v2){
                curr2=st2.top();
                st2.pop();
                ans.push_back(v2);
                curr2=curr2->right;
            }else{
                curr1=st1.top(); curr2=st2.top();
                st1.pop(); st2.pop();
                ans.push_back(v1);
                ans.push_back(v2);
                curr1=curr1->right;
                curr2=curr2->right;
            }
        }
        return ans;
    }
};