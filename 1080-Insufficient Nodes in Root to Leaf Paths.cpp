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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        dfs(root, limit, root -> val);
        return root;
    }
    void dfs(TreeNode* &root, int limit, int sum) {
        if (root -> left == NULL && root -> right == NULL) {
            if (sum < limit)
                root = NULL;
            return;
        }
        if (root -> left) {
            dfs(root -> left, limit, sum + root -> left -> val);
        }
        if (root -> right) {
            dfs(root -> right, limit, sum + root -> right -> val);
        }
        if (root -> left == NULL && root -> right == NULL)
            root = NULL;
    }
};