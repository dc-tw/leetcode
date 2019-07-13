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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *c = newHead, *p = c->next;

        while (c->next && c->next->next) {
            if (c->next->val == c->next->next->val) {
                p = p->next;
                while (p->next && p->val == p->next->val) {
                    p = p->next;
                }
                c->next = p->next;
            }//not duplicate
            else {
                c = c->next;
                p = p->next;
            }
        }
        return newHead->next;
    }
};//c=current new node