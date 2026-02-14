/*
class Node {
  public:
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
  
    void solve(Node* root, int k, long long currSum,
               unordered_map<long long,int> &mp, int &count) {
        
        if(root == NULL) return;
        
        currSum += root->data;
        
        // If path from root equals k
        if(currSum == k) count++;
        
        // If some prefix exists
        if(mp.find(currSum - k) != mp.end()) {
            count += mp[currSum - k];
        }
        
        mp[currSum]++;
        
        solve(root->left, k, currSum, mp, count);
        solve(root->right, k, currSum, mp, count);
        
        mp[currSum]--; // backtrack
    }
  
    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int> mp;
        int count = 0;
        solve(root, k, 0, mp, count);
        return count;
    }
};
