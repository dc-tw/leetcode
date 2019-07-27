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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)return 0;
        int sum = sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        }
        return sum;
    }
};