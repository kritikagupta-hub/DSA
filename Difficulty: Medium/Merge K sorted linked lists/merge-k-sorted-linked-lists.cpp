/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

#define pin pair<int, Node*>
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        // Create a min-heap to store pairs of (value, node pointer)
        priority_queue<pin, vector<pin>, greater<pin>> pq;
        
        // Iterate through each linked list in the input array
        for(auto &x : arr){
            Node* ptr = x;
            // Traverse each list and push every node into the heap
            while(ptr != nullptr){
                pq.push(make_pair(ptr->data, ptr));
                ptr = ptr->next;
            }
        }
        
        // Create a dummy head to simplify list construction
        Node* head = new Node(-1);
        Node* ans = head;
        
        // Extract all elements from the heap and build the sorted list
        while(!pq.empty()){
            auto top = pq.top(); 
            pq.pop();
            Node* node = top.second;
            // Attach the node to the result list
            ans->next = node;
            ans = ans->next;
        }
        
        // Ensure the last node points to nullptr
        ans->next = nullptr;
        
        // Return the merged list, which starts from head->next
        return head->next;
    }
};