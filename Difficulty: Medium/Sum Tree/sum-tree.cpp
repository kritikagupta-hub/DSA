/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
private:
    pair<bool, int> isSumTreeFast(Node* root) {
        // Base case: empty tree
        if (root == NULL) {
            return {true, 0};
        }

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return {true, root->data};
        }

        // Recursive calls
        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);

        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        int leftSum = leftAns.second;
        int rightSum = rightAns.second;

        bool cond = (root->data == leftSum + rightSum);

        pair<bool, int> ans;
        if (isLeftSumTree && isRightSumTree && cond) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        } else {
            ans.first = false;
            ans.second = 0;
        }

        return ans;
    }

public:
    bool isSumTree(Node* root) {
        return isSumTreeFast(root).first;
    }
};
