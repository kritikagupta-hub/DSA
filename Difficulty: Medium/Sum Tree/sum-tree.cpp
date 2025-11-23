/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<bool,int> isSumTreeFast(Node* root){
    // base case
    if(root == NULL){
        return {true, 0};
    }

    // leaf node: sum should be the leaf's value
    if(root->left == NULL && root->right == NULL){
        return {true, root->data};
    }
    
    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
    
    bool left = leftAns.first;
    bool right = rightAns.first;
    
    bool combo = (root->data == leftAns.second + rightAns.second);
    
    if(left && right && combo){
        return {true, root->data + leftAns.second + rightAns.second};
    }
    else{
        return {false, 0};
    }
}

    bool isSumTree(Node* root) {
        // Your code here
        return isSumTreeFast(root).first;
    }
};