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
    Node* parents(int target , Node* root , unordered_map<Node*,Node*>&parent){
        Node* targetnode=NULL;
        queue<Node*>store;
        store.push(root);
        while(!store.empty()){
            Node* curr=store.front();
            store.pop();
            if(curr->data==target) targetnode=curr;
            if(curr->left){
                store.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right){
                store.push(curr->right);
                parent[curr->right]=curr;
            }
        }
        return targetnode;
    }
    int burn(Node* target , unordered_map<Node*,Node*>&parent){
        queue<Node*>store;
        unordered_map<Node*,bool>visited;
        store.push(target);
        visited[target]=true;
        int times=0;
        while(!store.empty()){
            int n=store.size();
            bool found=false;
            for(int i=0;i<n;i++){
                Node* curr=store.front();
                store.pop();
                if(curr->left && !visited[curr->left]){
                    found=true;
                    visited[curr->left]=true;
                    store.push(curr->left);
                }
                if(curr->right && !visited[curr->right]){
                    found=true;
                    visited[curr->right]=true;
                    store.push(curr->right);
                }
                if(parent[curr] && !visited[parent[curr]]){
                    found=true;
                    visited[parent[curr]]=true;
                    store.push(parent[curr]);
                }
            }
            if(found) times++;
        }
        return times;
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>parent;
        Node *targetnode=parents(target,root,parent);
        return burn(targetnode,parent);
    }
};