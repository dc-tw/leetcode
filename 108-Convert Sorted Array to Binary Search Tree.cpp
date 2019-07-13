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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        root = helper(root, nums, 0, nums.size() - 1);
        return root;
    }

    TreeNode* helper(TreeNode* root, vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        root = new TreeNode(0);
        root->val = nums[(start + end + 1) / 2];
        root->left = helper(root->left, nums, start, (start + end + 1) / 2 - 1);
        root->right = helper(root->right, nums, (start + end + 1) / 2 + 1, end);
        return root;
    }
};