/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    void inorder(Node* root, vector<int> &in){
        if(root == NULL){
            return;
        }
        inorder(root->left ,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    
    Node* inorderToBST(int s, int e, vector<int> &in){
        // base case
        if(s > e){
            return NULL;
        }
        
        int mid = s + (e - s) / 2;
        Node* root = new Node(in[mid]);
        
        root->left = inorderToBST(s, mid - 1, in);
        root->right = inorderToBST(mid + 1, e, in);
        
        return root;
    }
    
    Node* balanceBST(Node* root) {
        vector<int> inorderVal;
        
        // Step 1: Store inorder (sorted values)
        inorder(root, inorderVal);
        
        // Step 2: Convert sorted array to balanced BST
        return inorderToBST(0, inorderVal.size() - 1, inorderVal);
    }
};