/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroDummy = new Node(-1);
        Node* oneDummy = new Node(-1);
        Node* twoDummy = new Node(-1);
        
        Node* z1 = zeroDummy;
        Node* o1 = oneDummy;
        Node* t1 = twoDummy;
        
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data == 0){
                z1->next=curr;
                z1=z1->next;
            }
            else if(curr->data == 1){
                o1->next=curr;
                o1=o1->next;
            }
            else{
                t1->next=curr;
                t1=t1->next;
            }
        
            curr = curr->next;
        }
        z1->next = oneDummy->next !=NULL ? oneDummy->next:twoDummy->next;
        o1->next = twoDummy->next;
        t1->next = NULL;
        return zeroDummy->next;
    }
};