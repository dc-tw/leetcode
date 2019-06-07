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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l3(0), *p = &l3;
        int sum = 0;

        while(l1 || l2 || sum){
            sum = (l1?l1->val:0) + (l2?l2->val:0) + sum;
            p->next = new ListNode(sum%10);
            sum /= 10;

            p = p->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return l3.next;
    }
};
// new is important
// pointer link-list
