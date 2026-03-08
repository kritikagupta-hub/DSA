/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* head=new Node(0);
        // add a dummy value to avoid condition of null for tail or head
        Node* tail=head;
        while(head1 && head2){
            if(head1->data<=head2->data){
                tail->next=head1;
                head1=head1->next;
                tail=tail->next;
                tail->next=nullptr;
            }
            // tail is connected to head1/head2 and make head1/head2 and 
            // tail to move forward and make tail-> next=nullptr
            else{
                tail->next=head2;
                head2=head2->next;
                tail=tail->next;
                tail->next=nullptr;
            }
        }
        // if head1 / head2 elements left over
        if(head1){
            tail->next=head1;
        }
        if(head2){
            tail->next=head2;
        }
        // delete that dummy value which created
        tail=head;
        head=head->next;
        delete tail;
        return head;
    }
};