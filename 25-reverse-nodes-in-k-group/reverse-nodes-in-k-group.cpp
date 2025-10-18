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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        // 1) Check if there are at least k nodes
        ListNode* temp = head;
        int cnt = 0;
        while (temp && cnt < k) {
            temp = temp->next;
            cnt++;
        }
        if (cnt < k) return head; // fewer than k nodes -> do not reverse

        // 2) Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        cnt = 0;
        while (curr && cnt < k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }

        // 3) head is now tail of reversed group
        head->next = reverseKGroup(nxt, k);

        return prev; // new head of reversed group
    }
};
