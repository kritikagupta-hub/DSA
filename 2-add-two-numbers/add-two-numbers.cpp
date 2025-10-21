/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insertAtTail(struct ListNode*&head,struct ListNode*&tail,int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head= temp;
            tail= temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }

    struct ListNode* add(struct ListNode*l1,struct ListNode*l2){
        int carry =0;
        ListNode*ansHead = NULL;
        ListNode*ansTail = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return ansHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Do NOT reverse — input is already in reverse order
        return add(l1, l2);
    }
};
