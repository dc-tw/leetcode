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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) {
            return head;
        } else if (m <= 0) {
            n = n + (1 - m);
            m = 1;
        }

        int i = 1;
        ListNode *index = head;
        vector<int> subArray;
        while (i < m) {
            if (index->next == NULL) {
                return head;
            } else {
                index = index->next;
                i++;
            } 
        }
        ListNode *preIndex = index;

        while (i <= n) {
            if (index == NULL) {
                break;
            }
            subArray.push_back(index->val);
            index = index->next;
            i++;
        }

        for (int j = subArray.size() - 1; j >= 0; j--) {
            preIndex->val = subArray[j];
            preIndex = preIndex->next;
        }

        return head;
    }
};