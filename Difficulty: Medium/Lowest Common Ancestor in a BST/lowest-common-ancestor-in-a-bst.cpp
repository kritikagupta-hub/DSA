/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        //if no is n1 and n2 it is null 
        if(root == NULL){
            return NULL;
        }
        // if n1 or n2 mill gy then return root
        if(root == n1 || root== n2){
            return root;
        }
        // Traverse--
        Node* leftAns = LCA(root->left,n1,n2);
        Node* rightAns= LCA(root->right,n1,n2);
        // if left se ans mila and right se bhi nila then that is ans
        if(leftAns != NULL && rightAns != NULL){
            return root;
        }
        // if any one is non null then return that side
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
        
    }
};