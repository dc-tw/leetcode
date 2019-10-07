/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }
        return dfs(&head, 0, n);
    }
 
    TreeNode * dfs(ListNode **head, int l, int r) {
        if (l == r) {
            return nullptr;
        }
 
        int m = l + ((r - l) / 2);
        auto left = dfs(head, l, m);
        auto curr = new TreeNode((*head)->val);
 
        *head = (*head)->next;
        curr->left = left;
        curr->right = dfs(head, m + 1, r);
        return curr;
    }
};