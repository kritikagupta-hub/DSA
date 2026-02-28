/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    bool checkBST(Node* root, long min, long max) {
        if (root == NULL) {
            return true;
        }
        
        // If value violates BST condition
        if (root->data <= min || root->data >= max) {
            return false;
        }
        
        return checkBST(root->left, min, root->data) &&
               checkBST(root->right, root->data, max);
    }
  
    bool isBST(Node* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};