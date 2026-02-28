/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        Node* temp = root;
        
        while (temp != NULL) {
            
            if (temp->data == key) {
                return true;
            }
            else if (key < temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        
        return false;  // If not found
    }
};