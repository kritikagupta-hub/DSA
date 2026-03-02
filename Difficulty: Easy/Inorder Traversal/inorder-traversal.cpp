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
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> v;
        if (root->left != NULL) {
            vector<int> v2 = inOrder(root->left);
            v.insert(v.end(), v2.begin(), v2.end());
        }
        v.push_back(root->data);
        if (root->right != NULL) {
            vector<int> v2 = inOrder(root->right);
            v.insert(v.end(), v2.begin(), v2.end());
        }
        return v;
    }
};