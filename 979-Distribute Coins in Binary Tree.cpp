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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
private:
    int dfs(TreeNode* root, int& ans) {
        if (!root) return 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        ans += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
};