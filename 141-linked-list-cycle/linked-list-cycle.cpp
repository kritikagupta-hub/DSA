/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //empty list logic
        if(head==NULL){
            return NULL;
        }
        //have single node in ll
        if(head->next==NULL){
            return false;
        }
        // floyd's detection algorithm slow=1 step and fast = 2 steps 
        //when they both meet that means cycle is present.
        ListNode * slow=head;
        ListNode * fast=head;
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};