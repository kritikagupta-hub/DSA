// User function Template for C++

class Solution {
  public:
    void flatten(Node *root) {
        // code here
        // finding right most node of left sub tree
        Node* curr = root;
        while(curr != NULL){
            if(curr->left)
            {
                Node* prev = curr->left;
                while(prev->right)
                {
                    prev = prev->right;
                }
                // conect original right sub tree
                prev->right = curr->right;
                //move left sub tree to right
                curr->right = curr->left;
                //left is NULL
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};