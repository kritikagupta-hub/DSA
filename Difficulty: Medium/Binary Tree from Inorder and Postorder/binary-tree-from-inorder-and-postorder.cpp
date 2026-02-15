/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    
    Node* solve(int in[], int post[], int &index,
                int inorderStart, int inorderEnd, int n,
                map<int,int> &nodeToIndex){
        
        // base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element = post[index--];
        Node* root = new Node(element);
        
        int position = nodeToIndex[element];
        
        // IMPORTANT: right first (because postorder = L R Root)
        root->right = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex);
        root->left  = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        
        int n = inorder.size();
        int postOrderIndex = n - 1;
        
        map<int,int> nodeToIndex;
        
        // create mapping
        createMapping(inorder.data(), nodeToIndex, n);
        
        Node* ans = solve(inorder.data(), postorder.data(),
                          postOrderIndex, 0, n - 1,
                          n, nodeToIndex);
        
        return ans;
    }
};
