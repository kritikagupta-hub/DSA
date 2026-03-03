/*
Node is as follows
class Node {
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
    void inorder(Node* root, vector<int> &in) {
        if (root == NULL) return;
        
        inorder(root->left, in);
        in.push_back(root->data);   // push_back is preferred
        inorder(root->right, in);
    }
    
    bool findTarget(Node *root, int target) {
        if (root == NULL) return false;   // safety check
        
        vector<int> inorderVal;
        inorder(root, inorderVal);
        
        int i = 0;
        int j = inorderVal.size() - 1;
        
        while (i < j) {
            int sum = inorderVal[i] + inorderVal[j];
            
            if (sum == target) {
                return true;
            }
            else if (sum > target) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return false;
    }
};